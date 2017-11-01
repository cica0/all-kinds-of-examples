#下面这个指令定义工程的名称，并可以指定支持的语言（可选）
#PROJECT_BINARY_DIR和PROJECT_SOURCE_DIR为自动生成
PROJECT (HELLO)
SET (SRC_LIST main.c)
#编译目录，如果是外部编译，此目录为build的路径。
MESSAGE(STATUS "This is BINARY dir" ${PROJECT_BINARY_DIR})
#工程目录，此路径一直为工程路径
MESSAGE(STATUS "This is SOURCE dir" ${HELLO_SOURCE_DIR})
#打印输出信息，第一个参数为STATUS代表输出前缀为-的信息
ADD_EXECUTABLE(hello ${SRC_LIST})
