# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/bjliuchang5/software/cmake/cmake-3.6/bin/cmake

# The command to remove a file.
RM = /home/bjliuchang5/software/cmake/cmake-3.6/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bjliuchang5/study/cmake/practice/t3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bjliuchang5/study/cmake/practice/t3/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/hello.dir/flags.make

lib/CMakeFiles/hello.dir/hello.o: lib/CMakeFiles/hello.dir/flags.make
lib/CMakeFiles/hello.dir/hello.o: ../lib/hello.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bjliuchang5/study/cmake/practice/t3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/hello.dir/hello.o"
	cd /home/bjliuchang5/study/cmake/practice/t3/build/lib && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hello.dir/hello.o   -c /home/bjliuchang5/study/cmake/practice/t3/lib/hello.c

lib/CMakeFiles/hello.dir/hello.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello.dir/hello.i"
	cd /home/bjliuchang5/study/cmake/practice/t3/build/lib && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bjliuchang5/study/cmake/practice/t3/lib/hello.c > CMakeFiles/hello.dir/hello.i

lib/CMakeFiles/hello.dir/hello.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello.dir/hello.s"
	cd /home/bjliuchang5/study/cmake/practice/t3/build/lib && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bjliuchang5/study/cmake/practice/t3/lib/hello.c -o CMakeFiles/hello.dir/hello.s

lib/CMakeFiles/hello.dir/hello.o.requires:

.PHONY : lib/CMakeFiles/hello.dir/hello.o.requires

lib/CMakeFiles/hello.dir/hello.o.provides: lib/CMakeFiles/hello.dir/hello.o.requires
	$(MAKE) -f lib/CMakeFiles/hello.dir/build.make lib/CMakeFiles/hello.dir/hello.o.provides.build
.PHONY : lib/CMakeFiles/hello.dir/hello.o.provides

lib/CMakeFiles/hello.dir/hello.o.provides.build: lib/CMakeFiles/hello.dir/hello.o


# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/hello.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

lib/libhello.so.1.2: lib/CMakeFiles/hello.dir/hello.o
lib/libhello.so.1.2: lib/CMakeFiles/hello.dir/build.make
lib/libhello.so.1.2: lib/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bjliuchang5/study/cmake/practice/t3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libhello.so"
	cd /home/bjliuchang5/study/cmake/practice/t3/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)
	cd /home/bjliuchang5/study/cmake/practice/t3/build/lib && $(CMAKE_COMMAND) -E cmake_symlink_library libhello.so.1.2 libhello.so.1 libhello.so

lib/libhello.so.1: lib/libhello.so.1.2
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libhello.so.1

lib/libhello.so: lib/libhello.so.1.2
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libhello.so

# Rule to build all files generated by this target.
lib/CMakeFiles/hello.dir/build: lib/libhello.so

.PHONY : lib/CMakeFiles/hello.dir/build

lib/CMakeFiles/hello.dir/requires: lib/CMakeFiles/hello.dir/hello.o.requires

.PHONY : lib/CMakeFiles/hello.dir/requires

lib/CMakeFiles/hello.dir/clean:
	cd /home/bjliuchang5/study/cmake/practice/t3/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/hello.dir/clean

lib/CMakeFiles/hello.dir/depend:
	cd /home/bjliuchang5/study/cmake/practice/t3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bjliuchang5/study/cmake/practice/t3 /home/bjliuchang5/study/cmake/practice/t3/lib /home/bjliuchang5/study/cmake/practice/t3/build /home/bjliuchang5/study/cmake/practice/t3/build/lib /home/bjliuchang5/study/cmake/practice/t3/build/lib/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/hello.dir/depend

