cmake_minimum_required(VERSION 2.6.0)

set(HOME "/home/chang/")
set(PACKAGE_NAME "gperftools_test")
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
    "${HOME}/work/common/third/boost/include/"
    "${HOME}/work/common/third/libunwind/include/"
    "${HOME}/software/gperftools-2.5-install/include/"
    )

link_directories(
    "${HOME}/work/common/third/glog/lib/"
    "${HOME}/work/common/third/gflags/lib/"
    "${HOME}/work/common/third/boost/lib/"
    "${HOME}/work/common/third/libunwind/lib/"
    "${HOME}/software/gperftools-2.5-install/lib/"
    )

set(SRCS
    "main.cpp"
   )

add_executable(${PACKAGE_NAME} ${SRCS})
target_link_libraries(${PACKAGE_NAME} 
    libglog.a 
    libgflags.a 
    libboost_system.a
    libboost_thread.a
    libunwind.a
    libprofiler.a
    )

#include(test)
#enable_testing()
#add_subdirectory(test)
