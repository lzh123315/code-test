# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lzh/code-test/lamba_cppad_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzh/code-test/lamba_cppad_test

# Include any dependencies generated for this target.
include CMakeFiles/ipopt_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ipopt_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ipopt_test.dir/flags.make

CMakeFiles/ipopt_test.dir/test.cpp.o: CMakeFiles/ipopt_test.dir/flags.make
CMakeFiles/ipopt_test.dir/test.cpp.o: test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzh/code-test/lamba_cppad_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ipopt_test.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ipopt_test.dir/test.cpp.o -c /home/lzh/code-test/lamba_cppad_test/test.cpp

CMakeFiles/ipopt_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ipopt_test.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzh/code-test/lamba_cppad_test/test.cpp > CMakeFiles/ipopt_test.dir/test.cpp.i

CMakeFiles/ipopt_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ipopt_test.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzh/code-test/lamba_cppad_test/test.cpp -o CMakeFiles/ipopt_test.dir/test.cpp.s

CMakeFiles/ipopt_test.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/ipopt_test.dir/test.cpp.o.requires

CMakeFiles/ipopt_test.dir/test.cpp.o.provides: CMakeFiles/ipopt_test.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/ipopt_test.dir/build.make CMakeFiles/ipopt_test.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/ipopt_test.dir/test.cpp.o.provides

CMakeFiles/ipopt_test.dir/test.cpp.o.provides.build: CMakeFiles/ipopt_test.dir/test.cpp.o


# Object files for target ipopt_test
ipopt_test_OBJECTS = \
"CMakeFiles/ipopt_test.dir/test.cpp.o"

# External object files for target ipopt_test
ipopt_test_EXTERNAL_OBJECTS =

ipopt_test: CMakeFiles/ipopt_test.dir/test.cpp.o
ipopt_test: CMakeFiles/ipopt_test.dir/build.make
ipopt_test: CMakeFiles/ipopt_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzh/code-test/lamba_cppad_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ipopt_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ipopt_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ipopt_test.dir/build: ipopt_test

.PHONY : CMakeFiles/ipopt_test.dir/build

CMakeFiles/ipopt_test.dir/requires: CMakeFiles/ipopt_test.dir/test.cpp.o.requires

.PHONY : CMakeFiles/ipopt_test.dir/requires

CMakeFiles/ipopt_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ipopt_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ipopt_test.dir/clean

CMakeFiles/ipopt_test.dir/depend:
	cd /home/lzh/code-test/lamba_cppad_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzh/code-test/lamba_cppad_test /home/lzh/code-test/lamba_cppad_test /home/lzh/code-test/lamba_cppad_test /home/lzh/code-test/lamba_cppad_test /home/lzh/code-test/lamba_cppad_test/CMakeFiles/ipopt_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ipopt_test.dir/depend

