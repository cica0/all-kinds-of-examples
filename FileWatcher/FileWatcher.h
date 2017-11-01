// FileWatcher.h
/*
FileWatcher监视文件的更新，当有更新时触发动作，一般用于配置文件的自动加载。
FileWatcher有个独立线程查看文件的更新。
应该用singleton来保证单个线程。
触发器将在该线程中执行，所以触发动作须保证线程安全。
首次调用Watch()时会开始线程。
*/
#include "time.h"
#include <boost/foreach.hpp>
#include <boost/function.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread/thread.hpp>  
#include <boost/atomic.hpp>

// 默认或出错时的文件时间
const time_t FILE_ERROR_TIME(-1);

class FileWatcher
{
public:
    FileWatcher();
    virtual ~FileWatcher();
    
public:    
    typedef boost::function<void ()> Trigger;  // 触发器
    // Watch()允许重复调用。首次调用会即时触发动作。
    void Watch(const std::string & sFileName, const Trigger & trigger);
    // TODO: Watch(sFile, trigger, milliSec) 支持自定义时间间隔
    
private:
    void StartLoopThreadIfNot();
    void Loop();
    void RecordFileTime(const std::string & sFileName, time_t tFileWrite);    
    time_t GetFileWriteTime(const std::string & sFileName) const;
    
private:
    struct WatchInfo
    {
        Trigger trigger;
        time_t tFileWrite;  // 文件更新时间
        WatchInfo() : tFileWrite(FILE_ERROR_TIME) {};
    };
    typedef std::map<std::string, WatchInfo> FileWatchMap;
    
private:
    WatchInfo UpdateWatch(const std::string & sFileName,
        const Trigger & trigger);
    FileWatchMap GetMapCopy();
    void WatchFile(const FileWatchMap::value_type & v);
    void WatchFile(const std::string & sFileName, const WatchInfo & wi);
    
private:
    FileWatchMap m_map;
    
    boost::scoped_ptr<boost::thread> m_pThread;
    boost::mutex m_mutex;
    typedef boost::lock_guard<boost::mutex> Guard;
    
    boost::atomic_bool m_bRun;    
};
