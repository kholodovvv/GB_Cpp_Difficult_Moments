# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "I:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "I:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "I:\CLion Projects\lesson7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "I:\CLion Projects\lesson7\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lesson7.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lesson7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lesson7.dir/flags.make

CMakeFiles/lesson7.dir/main.cpp.obj: CMakeFiles/lesson7.dir/flags.make
CMakeFiles/lesson7.dir/main.cpp.obj: CMakeFiles/lesson7.dir/includes_CXX.rsp
CMakeFiles/lesson7.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="I:\CLion Projects\lesson7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lesson7.dir/main.cpp.obj"
	I:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lesson7.dir\main.cpp.obj -c "I:\CLion Projects\lesson7\main.cpp"

CMakeFiles/lesson7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lesson7.dir/main.cpp.i"
	I:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "I:\CLion Projects\lesson7\main.cpp" > CMakeFiles\lesson7.dir\main.cpp.i

CMakeFiles/lesson7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lesson7.dir/main.cpp.s"
	I:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "I:\CLion Projects\lesson7\main.cpp" -o CMakeFiles\lesson7.dir\main.cpp.s

# Object files for target lesson7
lesson7_OBJECTS = \
"CMakeFiles/lesson7.dir/main.cpp.obj"

# External object files for target lesson7
lesson7_EXTERNAL_OBJECTS =

lesson7.exe: CMakeFiles/lesson7.dir/main.cpp.obj
lesson7.exe: CMakeFiles/lesson7.dir/build.make
lesson7.exe: CMakeFiles/lesson7.dir/linklibs.rsp
lesson7.exe: CMakeFiles/lesson7.dir/objects1.rsp
lesson7.exe: CMakeFiles/lesson7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="I:\CLion Projects\lesson7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lesson7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lesson7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lesson7.dir/build: lesson7.exe
.PHONY : CMakeFiles/lesson7.dir/build

CMakeFiles/lesson7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lesson7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lesson7.dir/clean

CMakeFiles/lesson7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "I:\CLion Projects\lesson7" "I:\CLion Projects\lesson7" "I:\CLion Projects\lesson7\cmake-build-debug" "I:\CLion Projects\lesson7\cmake-build-debug" "I:\CLion Projects\lesson7\cmake-build-debug\CMakeFiles\lesson7.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lesson7.dir/depend

