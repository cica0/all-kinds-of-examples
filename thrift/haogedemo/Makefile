SOURCE := $(wildcard gen-cpp/*.cpp) client.cpp server.cpp

OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

TARGET_SERVER := thrift-demo

CC		 := gcc
LIBS	 := -L
DEFINES  := 
LDFLAGS  := -lthrift -lrt 
INCLUDE  := -I ../gen-cpp/
CFLAGS 	 := -g -Wall $(DEFINES) $(INCLUDE)
CXXFLAGS := $(CFLAGS) 

$(TARGET_SERVER):$(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

.PHONY:clean
clean:
	rm -rf *.so
	rm -rf *.o
	rm -rf $(OBJS)
	rm -rf $(TARGET_SERVER)
