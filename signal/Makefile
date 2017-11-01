SOURCE := $(wildcard *.cpp) 

OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

TARGET := signal

CC		 := g++
#LIBS	 := -L
DEFINES  := 
#LDFLAGS  := -lm
#INCLUDE  := -I 
CFLAGS 	 := -g -Wall $(DEFINES) $(INCLUDE)
CXXFLAGS := $(CFLAGS) 

$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

.PHONY:clean
clean:
	rm -rf *.so
	rm -rf *.o
	rm -rf $(OBJS)
	rm -rf $(TARGET_SERVER)
