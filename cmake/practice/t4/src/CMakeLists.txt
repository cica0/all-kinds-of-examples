ADD_EXECUTABLE(main main.c)

#用来引入头文件
INCLUDE_DIRECTORIES(/home/bjliuchang5/study/cmake/practice/t3/usr/include/hello)

#添加共享库的搜索路径
LINK_DIRECTORIES(/home/bjliuchang5/study/cmake/practice/t3/usr/lib)

#为target添加需要链接的共享库,优先选择动态库
TARGET_LINK_LIBRARIES(main hello)
#TARGET_LINK_LIBRARIES(main libhello.a)
