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
include CMakeFiles/LinkStack.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/LinkStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkStack.dir/flags.make

CMakeFiles/LinkStack.dir/Stack/lstack.c.o: CMakeFiles/LinkStack.dir/flags.make
CMakeFiles/LinkStack.dir/Stack/lstack.c.o: ../Stack/lstack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/littlebear/CLionProjects/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LinkStack.dir/Stack/lstack.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LinkStack.dir/Stack/lstack.c.o -c /home/littlebear/CLionProjects/DataStructure/Stack/lstack.c

CMakeFiles/LinkStack.dir/Stack/lstack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LinkStack.dir/Stack/lstack.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/littlebear/CLionProjects/DataStructure/Stack/lstack.c > CMakeFiles/LinkStack.dir/Stack/lstack.c.i

CMakeFiles/LinkStack.dir/Stack/lstack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LinkStack.dir/Stack/lstack.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/littlebear/CLionProjects/DataStructure/Stack/lstack.c -o CMakeFiles/LinkStack.dir/Stack/lstack.c.s

# Object files for target LinkStack
LinkStack_OBJECTS = \
"CMakeFiles/LinkStack.dir/Stack/lstack.c.o"

# External object files for target LinkStack
LinkStack_EXTERNAL_OBJECTS =

LinkStack: CMakeFiles/LinkStack.dir/Stack/lstack.c.o
LinkStack: CMakeFiles/LinkStack.dir/build.make
LinkStack: CMakeFiles/LinkStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/littlebear/CLionProjects/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LinkStack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkStack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkStack.dir/build: LinkStack
.PHONY : CMakeFiles/LinkStack.dir/build

CMakeFiles/LinkStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinkStack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinkStack.dir/clean

CMakeFiles/LinkStack.dir/depend:
	cd /home/littlebear/CLionProjects/DataStructure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/littlebear/CLionProjects/DataStructure /home/littlebear/CLionProjects/DataStructure /home/littlebear/CLionProjects/DataStructure/cmake-build-debug /home/littlebear/CLionProjects/DataStructure/cmake-build-debug /home/littlebear/CLionProjects/DataStructure/cmake-build-debug/CMakeFiles/LinkStack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkStack.dir/depend

