# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chang/study/all-kinds-of-examples/DesignPattern/Factory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/build

# Include any dependencies generated for this target.
include CMakeFiles/factory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/factory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/factory.dir/flags.make

CMakeFiles/factory.dir/AbstractFactory.cpp.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/AbstractFactory.cpp.o: ../AbstractFactory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/factory.dir/AbstractFactory.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/factory.dir/AbstractFactory.cpp.o -c /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/AbstractFactory.cpp

CMakeFiles/factory.dir/AbstractFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/factory.dir/AbstractFactory.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/AbstractFactory.cpp > CMakeFiles/factory.dir/AbstractFactory.cpp.i

CMakeFiles/factory.dir/AbstractFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/factory.dir/AbstractFactory.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/AbstractFactory.cpp -o CMakeFiles/factory.dir/AbstractFactory.cpp.s

CMakeFiles/factory.dir/AbstractFactory.cpp.o.requires:
.PHONY : CMakeFiles/factory.dir/AbstractFactory.cpp.o.requires

CMakeFiles/factory.dir/AbstractFactory.cpp.o.provides: CMakeFiles/factory.dir/AbstractFactory.cpp.o.requires
	$(MAKE) -f CMakeFiles/factory.dir/build.make CMakeFiles/factory.dir/AbstractFactory.cpp.o.provides.build
.PHONY : CMakeFiles/factory.dir/AbstractFactory.cpp.o.provides

CMakeFiles/factory.dir/AbstractFactory.cpp.o.provides.build: CMakeFiles/factory.dir/AbstractFactory.cpp.o

# Object files for target factory
factory_OBJECTS = \
"CMakeFiles/factory.dir/AbstractFactory.cpp.o"

# External object files for target factory
factory_EXTERNAL_OBJECTS =

factory: CMakeFiles/factory.dir/AbstractFactory.cpp.o
factory: CMakeFiles/factory.dir/build.make
factory: CMakeFiles/factory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable factory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/factory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/factory.dir/build: factory
.PHONY : CMakeFiles/factory.dir/build

CMakeFiles/factory.dir/requires: CMakeFiles/factory.dir/AbstractFactory.cpp.o.requires
.PHONY : CMakeFiles/factory.dir/requires

CMakeFiles/factory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/factory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/factory.dir/clean

CMakeFiles/factory.dir/depend:
	cd /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chang/study/all-kinds-of-examples/DesignPattern/Factory /home/chang/study/all-kinds-of-examples/DesignPattern/Factory /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/build /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/build /home/chang/study/all-kinds-of-examples/DesignPattern/Factory/build/CMakeFiles/factory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/factory.dir/depend

