#
#TARGET = main
#
#SOURCE := $(wildcard *.cpp)
#OBJS := $(patsubst %.cpp,%.o,$(SOURCE))
#$(warning $(OBJS))
#LIBS := -lpthread
#INCLUDE := -I${HOME}/software/protobuf/protobuf/include/ 
#CXXFLAGS := -g -Wall 
#$(warning $(INCLUDE))
#
#.PHONY : clean 
#
#$(TARGET):$(OBJS)
#	GXX -o $@ -I${HOME}/software/protobuf/protobuf/include/ $(LIBS) -lpthread
#	
#clean:
#	rm -rf *.so
#	rm -rf *.o
#	rm -rf $(OBJS)
#	rm -rf $(TARGET)
######################################
#
######################################
#source file
#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件

#SOURCE  := $(wildcard ../gen-cpp/*.c) $(wildcard ../gen-cpp/*.cpp) 
SOURCE  := $(wildcard *.cpp ) 

OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE))) helloworld.pb.cc

#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET_SERVER  := main 
  
#compile and lib parameter
#编译参数
CC      := g++
LIBS    := -L${HOME}/software/protobuf/protobuf/lib
LDFLAGS := -lpthread -lprotobuf
DEFINES :=
INCLUDE :=-I${HOME}/software/protobuf/protobuf/include 
CFLAGS  := -g -Wall $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS) 
  
  
#i think you should do anything here
#下面的基本上不需要做任何改动了
.PHONY : everything objs clean veryclean rebuild
  
everything : $(TARGET_SERVER)
  
all : $(TARGET_SERVER)
  
objs : $(OBJS)
  
rebuild: veryclean everything
                
clean :
	rm -fr *.so
	rm -fr *.o
	rm -fr $(OBJS)
	rm -fr $(TARGET_SERVER) 
    
veryclean : clean
	rm -fr $(TARGET_SERVER)
  
$(TARGET_SERVER) : $(OBJS) 
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)



