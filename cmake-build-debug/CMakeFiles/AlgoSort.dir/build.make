# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/jetbrains/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/jetbrains/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sun/code/AlgoSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sun/code/AlgoSort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AlgoSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AlgoSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlgoSort.dir/flags.make

CMakeFiles/AlgoSort.dir/main.cpp.o: CMakeFiles/AlgoSort.dir/flags.make
CMakeFiles/AlgoSort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sun/code/AlgoSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AlgoSort.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AlgoSort.dir/main.cpp.o -c /home/sun/code/AlgoSort/main.cpp

CMakeFiles/AlgoSort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgoSort.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sun/code/AlgoSort/main.cpp > CMakeFiles/AlgoSort.dir/main.cpp.i

CMakeFiles/AlgoSort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgoSort.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sun/code/AlgoSort/main.cpp -o CMakeFiles/AlgoSort.dir/main.cpp.s

# Object files for target AlgoSort
AlgoSort_OBJECTS = \
"CMakeFiles/AlgoSort.dir/main.cpp.o"

# External object files for target AlgoSort
AlgoSort_EXTERNAL_OBJECTS =

AlgoSort: CMakeFiles/AlgoSort.dir/main.cpp.o
AlgoSort: CMakeFiles/AlgoSort.dir/build.make
AlgoSort: CMakeFiles/AlgoSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sun/code/AlgoSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AlgoSort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AlgoSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AlgoSort.dir/build: AlgoSort

.PHONY : CMakeFiles/AlgoSort.dir/build

CMakeFiles/AlgoSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AlgoSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AlgoSort.dir/clean

CMakeFiles/AlgoSort.dir/depend:
	cd /home/sun/code/AlgoSort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sun/code/AlgoSort /home/sun/code/AlgoSort /home/sun/code/AlgoSort/cmake-build-debug /home/sun/code/AlgoSort/cmake-build-debug /home/sun/code/AlgoSort/cmake-build-debug/CMakeFiles/AlgoSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AlgoSort.dir/depend

