//TODO: 不用独立线程，改为注册定时器，定时器运行于主线程，这样就不用加锁了。
// FileWatcher.cpp
#include "FileWatcher.h"
#include <sys/stat.h>

FileWatcher::FileWatcher() : m_bRun(true) {
}

FileWatcher::~FileWatcher() {
    m_bRun = false;
    m_pThread->join();
}

void FileWatcher::Watch(
    const std::string & sFileName, const Trigger & trigger) {
    if (!trigger) return;  // 不支持删除watch, 因为Loop()中已复制map.
    std::cout <<"trigger in " << __LINE__ << ":" << trigger << std::endl;
    const WatchInfo &wi = UpdateWatch(sFileName, trigger);
    WatchFile(sFileName, wi);  // 立即触发
    StartLoopThreadIfNot();
}

// 返回对应的WatchInfo.
FileWatcher::WatchInfo FileWatcher::UpdateWatch(
    const std::string & sFileName, const Trigger & trigger) {
    Guard guard(m_mutex);
    m_map[sFileName].trigger = trigger;
    // TODO: Same file but different name: ./f.ini = f.ini
    WatchInfo wi = m_map[sFileName];
    return wi;
}

void FileWatcher::StartLoopThreadIfNot() {
    if (m_pThread) return;  // thread is running
    m_bRun = true;
    m_pThread.reset(new boost::thread(
        boost::bind(&FileWatcher::Loop, this)));
}

void FileWatcher::Loop() {
    do {
        // 为了线程安全，需先复制
        FileWatchMap mapCopy = GetMapCopy();
        size_t nCount = mapCopy.size();
        const int LOOP_INTERVAL_MS = 1000;  // 循环间隔ms
        const int msSleep = LOOP_INTERVAL_MS / (1 + nCount);  // 无除0错误
        BOOST_FOREACH(const FileWatchMap::value_type & v, mapCopy) {
            WatchFile(v);
            if (m_bRun) {
                boost::this_thread::sleep_for(
                    boost::chrono::milliseconds(msSleep));
            }
        }
    } while (m_bRun);
}

// 获取副本，线程安全
FileWatcher::FileWatchMap FileWatcher::GetMapCopy() {
    Guard guard(m_mutex);
    return m_map;
}

void FileWatcher::WatchFile(const FileWatchMap::value_type & v) {
    WatchFile(v.first, v.second);
}

void FileWatcher::WatchFile(const std::string & sFileName, const WatchInfo & wi) {
    time_t tFileWrite = GetFileWriteTime(sFileName);
    if (tFileWrite == wi.tFileWrite) return;
    time_t tNow = time(NULL);
    if (tFileWrite == tNow || tFileWrite == tNow - 1)
        return;  // 文件正在更改，待改完后再触发
    BOOST_ASSERT(wi.trigger);
    std::cout <<"trigger iss:"<< wi.trigger << std::endl;
    wi.trigger();
    RecordFileTime(sFileName, tFileWrite);
}

void FileWatcher::RecordFileTime(const std::string & sFileName, time_t tFileWrite) {
    Guard guard(m_mutex);
    m_map[sFileName].tFileWrite = tFileWrite;
}

// 出错则返回FILE_ERROR_TIME
time_t FileWatcher::GetFileWriteTime(const std::string & sFileName) const {
    struct stat buf;
    if (stat(sFileName.c_str(), &buf))
        return FILE_ERROR_TIME;
    return buf.st_mtime;
}

