cmake_minimum_required(VERSION 2.6.0)

set(HOME "/home/chang/")
set(PACKAGE_NAME "thrift_target")
set(PACKAGE_VERSION "0.0.1.1")
set(PACKAGE_TARNAME "${PACKAGE_NAME}-${PACKAGE_VERSION}")
message (STATUS "PACKAGE_TARNAME" ${PACKAGE_TARNAME})
project(${PACKAGE_NAME} CXX)

set (CMAKE_CXX_FLAGS "-g -O0 -std=c++11")
add_definitions(-DTHREADED)
add_definitions(-DVERSION_ID="${PACKAGE_TARNAME}")
#DNDEBUG 禁用glog dlog 输出
add_definitions(-DNDEBUG)

set(THRIFT_IDL_DIR "${HOME}/study/thrift/student/gen-cpp")

include_directories(
    "${HOME}/work/common/third/glog/include/"
    "${HOME}/work/common/third/gflags/include/"
    "${HOME}/work/common/third/gtest/include/"
    "${THRIFT_IDL_DIR}"
    "${HOME}/study/thrift/student/thrift/include/"
    )

link_directories(
    "${HOME}/work/common/third/glog/lib/"
    "${HOME}/work/common/third/gflags/lib/"
    "${HOME}/work/common/third/gtest/lib/"
    "${HOME}/study/thrift/student/thrift/lib/"
    )


set(UFS_IDL_SRCS
    "${THRIFT_IDL_DIR}/putin.cpp"
    "${THRIFT_IDL_DIR}/getout.cpp"
    "${THRIFT_IDL_DIR}/student_constants.cpp"
    "${THRIFT_IDL_DIR}/student_types.cpp"
    )

set(SRCS
    "main.cpp"
   )

add_executable(${PACKAGE_NAME} ${SRCS} ${UFS_IDL_SRCS})
target_link_libraries(${PACKAGE_NAME} 
    libglog.a 
    libgtest.a 
    libgflags.a 
    pthread 
    libthrift.a
    )

#include(test)
#enable_testing()
#add_subdirectory(test)
