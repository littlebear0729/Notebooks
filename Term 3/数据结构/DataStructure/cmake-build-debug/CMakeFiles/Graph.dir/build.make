# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/littlebear/CLionProjects/DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/littlebear/CLionProjects/DataStructure/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Graph.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Graph.dir/flags.make

CMakeFiles/Graph.dir/Graph/graph_adjmat.c.o: CMakeFiles/Graph.dir/flags.make
CMakeFiles/Graph.dir/Graph/graph_adjmat.c.o: ../Graph/graph_adjmat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/littlebear/CLionProjects/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Graph.dir/Graph/graph_adjmat.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Graph.dir/Graph/graph_adjmat.c.o -c /home/littlebear/CLionProjects/DataStructure/Graph/graph_adjmat.c

CMakeFiles/Graph.dir/Graph/graph_adjmat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Graph.dir/Graph/graph_adjmat.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/littlebear/CLionProjects/DataStructure/Graph/graph_adjmat.c > CMakeFiles/Graph.dir/Graph/graph_adjmat.c.i

CMakeFiles/Graph.dir/Graph/graph_adjmat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Graph.dir/Graph/graph_adjmat.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/littlebear/CLionProjects/DataStructure/Graph/graph_adjmat.c -o CMakeFiles/Graph.dir/Graph/graph_adjmat.c.s

# Object files for target Graph
Graph_OBJECTS = \
"CMakeFiles/Graph.dir/Graph/graph_adjmat.c.o"

# External object files for target Graph
Graph_EXTERNAL_OBJECTS =

Graph: CMakeFiles/Graph.dir/Graph/graph_adjmat.c.o
Graph: CMakeFiles/Graph.dir/build.make
Graph: CMakeFiles/Graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/littlebear/CLionProjects/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Graph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Graph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Graph.dir/build: Graph
.PHONY : CMakeFiles/Graph.dir/build

CMakeFiles/Graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Graph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Graph.dir/clean

CMakeFiles/Graph.dir/depend:
	cd /home/littlebear/CLionProjects/DataStructure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/littlebear/CLionProjects/DataStructure /home/littlebear/CLionProjects/DataStructure /home/littlebear/CLionProjects/DataStructure/cmake-build-debug /home/littlebear/CLionProjects/DataStructure/cmake-build-debug /home/littlebear/CLionProjects/DataStructure/cmake-build-debug/CMakeFiles/Graph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Graph.dir/depend

