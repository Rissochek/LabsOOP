# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rusla\coding\LabsOOP\Lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rusla\coding\LabsOOP\Lab6\build

# Include any dependencies generated for this target.
include CMakeFiles/FactoryLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FactoryLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FactoryLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FactoryLib.dir/flags.make

CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.obj: CMakeFiles/FactoryLib.dir/flags.make
CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.obj: C:/Users/rusla/coding/LabsOOP/Lab6/lib/FactoryLib/Factory.cpp
CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.obj: CMakeFiles/FactoryLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rusla\coding\LabsOOP\Lab6\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.obj -MF CMakeFiles\FactoryLib.dir\lib\FactoryLib\Factory.cpp.obj.d -o CMakeFiles\FactoryLib.dir\lib\FactoryLib\Factory.cpp.obj -c C:\Users\rusla\coding\LabsOOP\Lab6\lib\FactoryLib\Factory.cpp

CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rusla\coding\LabsOOP\Lab6\lib\FactoryLib\Factory.cpp > CMakeFiles\FactoryLib.dir\lib\FactoryLib\Factory.cpp.i

CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rusla\coding\LabsOOP\Lab6\lib\FactoryLib\Factory.cpp -o CMakeFiles\FactoryLib.dir\lib\FactoryLib\Factory.cpp.s

# Object files for target FactoryLib
FactoryLib_OBJECTS = \
"CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.obj"

# External object files for target FactoryLib
FactoryLib_EXTERNAL_OBJECTS =

libFactoryLib.a: CMakeFiles/FactoryLib.dir/lib/FactoryLib/Factory.cpp.obj
libFactoryLib.a: CMakeFiles/FactoryLib.dir/build.make
libFactoryLib.a: CMakeFiles/FactoryLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\rusla\coding\LabsOOP\Lab6\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libFactoryLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\FactoryLib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FactoryLib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FactoryLib.dir/build: libFactoryLib.a
.PHONY : CMakeFiles/FactoryLib.dir/build

CMakeFiles/FactoryLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FactoryLib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FactoryLib.dir/clean

CMakeFiles/FactoryLib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rusla\coding\LabsOOP\Lab6 C:\Users\rusla\coding\LabsOOP\Lab6 C:\Users\rusla\coding\LabsOOP\Lab6\build C:\Users\rusla\coding\LabsOOP\Lab6\build C:\Users\rusla\coding\LabsOOP\Lab6\build\CMakeFiles\FactoryLib.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FactoryLib.dir/depend

