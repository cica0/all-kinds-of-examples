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
CMAKE_SOURCE_DIR = /home/chang/study/all-kinds-of-examples/gperftools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chang/study/all-kinds-of-examples/gperftools/build

# Include any dependencies generated for this target.
include CMakeFiles/gperftools_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gperftools_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gperftools_test.dir/flags.make

CMakeFiles/gperftools_test.dir/main.cpp.o: CMakeFiles/gperftools_test.dir/flags.make
CMakeFiles/gperftools_test.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chang/study/all-kinds-of-examples/gperftools/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gperftools_test.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gperftools_test.dir/main.cpp.o -c /home/chang/study/all-kinds-of-examples/gperftools/main.cpp

CMakeFiles/gperftools_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gperftools_test.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chang/study/all-kinds-of-examples/gperftools/main.cpp > CMakeFiles/gperftools_test.dir/main.cpp.i

CMakeFiles/gperftools_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gperftools_test.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chang/study/all-kinds-of-examples/gperftools/main.cpp -o CMakeFiles/gperftools_test.dir/main.cpp.s

CMakeFiles/gperftools_test.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/gperftools_test.dir/main.cpp.o.requires

CMakeFiles/gperftools_test.dir/main.cpp.o.provides: CMakeFiles/gperftools_test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/gperftools_test.dir/build.make CMakeFiles/gperftools_test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/gperftools_test.dir/main.cpp.o.provides

CMakeFiles/gperftools_test.dir/main.cpp.o.provides.build: CMakeFiles/gperftools_test.dir/main.cpp.o

# Object files for target gperftools_test
gperftools_test_OBJECTS = \
"CMakeFiles/gperftools_test.dir/main.cpp.o"

# External object files for target gperftools_test
gperftools_test_EXTERNAL_OBJECTS =

gperftools_test: CMakeFiles/gperftools_test.dir/main.cpp.o
gperftools_test: CMakeFiles/gperftools_test.dir/build.make
gperftools_test: CMakeFiles/gperftools_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable gperftools_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gperftools_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gperftools_test.dir/build: gperftools_test
.PHONY : CMakeFiles/gperftools_test.dir/build

CMakeFiles/gperftools_test.dir/requires: CMakeFiles/gperftools_test.dir/main.cpp.o.requires
.PHONY : CMakeFiles/gperftools_test.dir/requires

CMakeFiles/gperftools_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gperftools_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gperftools_test.dir/clean

CMakeFiles/gperftools_test.dir/depend:
	cd /home/chang/study/all-kinds-of-examples/gperftools/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chang/study/all-kinds-of-examples/gperftools /home/chang/study/all-kinds-of-examples/gperftools /home/chang/study/all-kinds-of-examples/gperftools/build /home/chang/study/all-kinds-of-examples/gperftools/build /home/chang/study/all-kinds-of-examples/gperftools/build/CMakeFiles/gperftools_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gperftools_test.dir/depend
