cmake_minimum_required(VERSION 2.6.0)

set(HOME "/home/chang/")
set(PACKAGE_NAME "threadpoll")
set(PACKAGE_VERSION "0.0.1.1")
set(PACKAGE_TARNAME "${PACKAGE_NAME}-${PACKAGE_VERSION}")
message (STATUS "PACKAGE_TARNAME" ${PACKAGE_TARNAME})
project(${PACKAGE_NAME} CXX)

set (CMAKE_CXX_FLAGS "-g -O0 -std=c++11")
add_definitions(-DTHREADED)
add_definitions(-DVERSION_ID="${PACKAGE_TARNAME}")
#DNDEBUG 禁用glog dlog 输出
add_definitions(-DNDEBUG)

include_directories(
    "${HOME}/work/common/third/glog/include/"
    "${HOME}/work/common/third/gflags/include/"
    "${HOME}/work/common/third/gtest/include/"
    "${HOME}/work/common/third/curl/include/"
    "${HOME}/work/common/third/boost/include/"
    )

link_directories(
    "${HOME}/work/common/third/glog/lib/"
    "${HOME}/work/common/third/gflags/lib/"
    "${HOME}/work/common/third/gtest/lib/"
    "${HOME}/work/common/third/curl/lib/"
    "${HOME}/work/common/third/boost/lib/"
    )

set(SRCS
    "threadpool.cpp"
   )

add_executable(${PACKAGE_NAME} ${SRCS})
target_link_libraries(${PACKAGE_NAME} 
    libglog.a 
    libgtest.a 
    libgflags.a 
    libcurl.a
    pthread 
    libboost_thread.a
    libboost_system.a
    )

