SET(LIBHELLO_SRC hello.c)
#ADD_LIBRARY第二个参数有三种：
#SHARED 动态库
#STATIC 静态库
ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})
#注意:这里的库的名称（第一个参数）是不能重名的,否则会将原来的挤没
ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC})
#这条指令用来设置输出的名称
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")
#这样就既有了hello.o和hello.so

#VERSION指代动态库版本，SOVERSION指代API版本
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

#此命令将各种静态库和动态库统一放在lib中，
#将hello.h放在include中
#静态库要使用ARCHIVE关键字
INSTALL(TARGETS hello hello_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
INSTALL(FILES hello.h DESTINATION include/hello) 
