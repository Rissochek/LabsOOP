# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/rusla/coding/LabsOOP/lab7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/rusla/coding/LabsOOP/lab7/build

# Include any dependencies generated for this target.
include src/CMakeFiles/core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/core.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/core.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/core.dir/flags.make

src/CMakeFiles/core.dir/main.cpp.o: src/CMakeFiles/core.dir/flags.make
src/CMakeFiles/core.dir/main.cpp.o: /mnt/c/Users/rusla/coding/LabsOOP/lab7/src/main.cpp
src/CMakeFiles/core.dir/main.cpp.o: src/CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/rusla/coding/LabsOOP/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/core.dir/main.cpp.o"
	cd /mnt/c/Users/rusla/coding/LabsOOP/lab7/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/core.dir/main.cpp.o -MF CMakeFiles/core.dir/main.cpp.o.d -o CMakeFiles/core.dir/main.cpp.o -c /mnt/c/Users/rusla/coding/LabsOOP/lab7/src/main.cpp

src/CMakeFiles/core.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/core.dir/main.cpp.i"
	cd /mnt/c/Users/rusla/coding/LabsOOP/lab7/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/rusla/coding/LabsOOP/lab7/src/main.cpp > CMakeFiles/core.dir/main.cpp.i

src/CMakeFiles/core.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/core.dir/main.cpp.s"
	cd /mnt/c/Users/rusla/coding/LabsOOP/lab7/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/rusla/coding/LabsOOP/lab7/src/main.cpp -o CMakeFiles/core.dir/main.cpp.s

# Object files for target core
core_OBJECTS = \
"CMakeFiles/core.dir/main.cpp.o"

# External object files for target core
core_EXTERNAL_OBJECTS =

src/core: src/CMakeFiles/core.dir/main.cpp.o
src/core: src/CMakeFiles/core.dir/build.make
src/core: src/CMakeFiles/core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/rusla/coding/LabsOOP/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable core"
	cd /mnt/c/Users/rusla/coding/LabsOOP/lab7/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/core.dir/build: src/core
.PHONY : src/CMakeFiles/core.dir/build

src/CMakeFiles/core.dir/clean:
	cd /mnt/c/Users/rusla/coding/LabsOOP/lab7/build/src && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/core.dir/clean

src/CMakeFiles/core.dir/depend:
	cd /mnt/c/Users/rusla/coding/LabsOOP/lab7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/rusla/coding/LabsOOP/lab7 /mnt/c/Users/rusla/coding/LabsOOP/lab7/src /mnt/c/Users/rusla/coding/LabsOOP/lab7/build /mnt/c/Users/rusla/coding/LabsOOP/lab7/build/src /mnt/c/Users/rusla/coding/LabsOOP/lab7/build/src/CMakeFiles/core.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/core.dir/depend

