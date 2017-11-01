cmake_minimum_required(VERSION 2.6.0)

set(HOME "/home/chang/")
set(COMMON "/home/chang/work/common/")
set(PACKAGE_NAME "heapprofile")
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
    "${COMMON}/third/glog/include/"
    "${COMMON}/third/gflags/include/"
    "${COMMON}/third/gtest/include/"
    "${COMMON}/base/third-64/tcmalloc_2-1-0-100_PD_BL/include/"
    )

link_directories(
    "${COMMON}/third/glog/lib/"
    "${COMMON}/third/gflags/lib/"
    "${COMMON}/third/gtest/lib/"
    "${COMMON}/base/third-64/tcmalloc_2-1-0-100_PD_BL/lib"
    )

set(SRCS
    "main.cpp"
   )

add_executable(${PACKAGE_NAME} ${SRCS})
target_link_libraries(${PACKAGE_NAME} 
    libglog.a 
    libgtest.a 
    libgflags.a 
    libprofiler.a
    libtcmalloc.a
    pthread 
    )

#include(test)
#enable_testing()
#add_subdirectory(test)
