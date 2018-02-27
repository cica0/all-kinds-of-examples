cmake_minimum_required(VERSION 2.6.0)

set(HOME "/home/chang/")
set(PACKAGE_NAME "factory")
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
    )

link_directories(
    "${HOME}/work/common/third/glog/lib/"
    "${HOME}/work/common/third/gflags/lib/"
    "${HOME}/work/common/third/gtest/lib/"
    )

set(SRCS
#    "main.cpp"
#    "Factory.cpp"
#    "ShapeFactory2.cpp"
    "AbstractFactory.cpp"
   )

add_executable(${PACKAGE_NAME} ${SRCS})
target_link_libraries(${PACKAGE_NAME} 
    libglog.a 
    libgtest.a 
    libgflags.a 
    pthread 
    )

#include(test)
#enable_testing()
#add_subdirectory(test)
