OBJECTS = unit gtest
GTESTINCLUDE=/home/bjliuchang5/software/gtest/googletest/googletest/include
GTESTLIB=/home/bjliuchang5/software/gtest/googletest/build/googlemock/gtest 

CXXFLAGS += -std=c++11  


all:$(OBJECTS)
%.o:%.cpp
	g++ -o $@ $< -I$(GTESTINCLUDE) -L$(GTESTLIB) -lpthread -lgtest

clean:
	rm $(OBJECTS)
