glog_example:
	g++ -o glog_example glog_example.cpp -I/home/bjliuchang5/software/glog/glog_install/include -L/home/bjliuchang5/software/glog/glog_install/lib -I/home/bjliuchang5/study/gflag/gflags/build/include -L/home/bjliuchang5/study/gflag/gflags/build/lib/ -pthread -lglog -lgflags
clean:
	rm glog_example
	
#GLOGLIB=$(HOME)/software/glog/glog_install/lib #glog 安装路径
#GFLAGSLIB=$(HOME)/study/gflag/gflags/build/lib #glog 安装路径
#GLOGINCLUDE=$(HOME)/software/glog/glog_install/include
#GFLAGSINCLUDE=$(HOME)/study/gflag/gflags/build/include/
#glog_example: glog_example.o
#	g++ -o $@ $^ -L$(GLOGLIB) -L$(GFLAGSLIB) -lglog -lpthread   
#glog_example.o: glog_example.cpp
#	g++ -c -o $@ $^ -I$(GLOGINCLUDE) -I$(GFLAGSINCLUDE) 
#clean:
#	rm glog_example
