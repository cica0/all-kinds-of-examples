cmake_minimum_required(VERSION 2.6.0)

##DNDEBUG 禁用glog dlog 输出
#add_definitions(-DNDEBUG)

include_directories(
    "${HOME}/software/redis-4.0.1/deps/"
    "${HOME}/work/common/third/glog/include/"
    "${HOME}/work/common/third/gflags/include/"
    "${HOME}/work/common/third/gtest/include/"
    )

link_directories(
    "${HOME}/software/redis-4.0.1/deps/hiredis/"
    "${HOME}/work/common/third/glog/lib/"
    "${HOME}/work/common/third/gflags/lib/"
    "${HOME}/work/common/third/gtest/lib/"
    )

set(TEST_SRCS
    "redis-server_test.cpp"
   )

add_executable(redis-server_test ${TEST_SRCS})
target_link_libraries(redis-server_test
    libglog.a 
    libgtest.a 
    libgflags.a 
    libhiredis.a
    pthread 
    )
