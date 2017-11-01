OBJECTS = lock
#GTESTINCLUDE=/home/bjliuchang5/software/gtest/googletest/googletest/include
#GTESTLIB=/home/bjliuchang5/software/gtest/googletest/build/googlemock/gtest 
GTESTINCLUDE=
GTESTLIB=

CXXFLAGS += -std=c++11  
LLIB = -lpthread


all:$(OBJECTS)
%.o:%.cpp
	g++ -o $@ $< -lpthread
#	$(LLIB) 
#	-I$(GTESTINCLUDE) -L$(GTESTLIB) 

clean:
	rm $(OBJECTS)
