cmake_minimum_required(VERSION 3.6)
PROJECT (HELLO)
ADD_SUBDIRECTORY(src bin)

INSTALL(FILES COPYRIGHT README DESTINATION /home/bjliuchang5/study/cmake/practice/t2)
INSTALL(PROGRAMS run.sh DESTINATION bin)
INSTALL (DIRECTORY doc/ DESTINATION /home/bjliuchang5/study/cmake/practice/t2)
