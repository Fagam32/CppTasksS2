# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CppProjects\S2.E1.T3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CppProjects\S2.E1.T3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/S2_E1_T3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/S2_E1_T3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/S2_E1_T3.dir/flags.make

CMakeFiles/S2_E1_T3.dir/main.cpp.obj: CMakeFiles/S2_E1_T3.dir/flags.make
CMakeFiles/S2_E1_T3.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CppProjects\S2.E1.T3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/S2_E1_T3.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\S2_E1_T3.dir\main.cpp.obj -c D:\CppProjects\S2.E1.T3\main.cpp

CMakeFiles/S2_E1_T3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S2_E1_T3.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CppProjects\S2.E1.T3\main.cpp > CMakeFiles\S2_E1_T3.dir\main.cpp.i

CMakeFiles/S2_E1_T3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S2_E1_T3.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CppProjects\S2.E1.T3\main.cpp -o CMakeFiles\S2_E1_T3.dir\main.cpp.s

# Object files for target S2_E1_T3
S2_E1_T3_OBJECTS = \
"CMakeFiles/S2_E1_T3.dir/main.cpp.obj"

# External object files for target S2_E1_T3
S2_E1_T3_EXTERNAL_OBJECTS =

S2_E1_T3.exe: CMakeFiles/S2_E1_T3.dir/main.cpp.obj
S2_E1_T3.exe: CMakeFiles/S2_E1_T3.dir/build.make
S2_E1_T3.exe: CMakeFiles/S2_E1_T3.dir/linklibs.rsp
S2_E1_T3.exe: CMakeFiles/S2_E1_T3.dir/objects1.rsp
S2_E1_T3.exe: CMakeFiles/S2_E1_T3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CppProjects\S2.E1.T3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable S2_E1_T3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\S2_E1_T3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/S2_E1_T3.dir/build: S2_E1_T3.exe

.PHONY : CMakeFiles/S2_E1_T3.dir/build

CMakeFiles/S2_E1_T3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\S2_E1_T3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/S2_E1_T3.dir/clean

CMakeFiles/S2_E1_T3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CppProjects\S2.E1.T3 D:\CppProjects\S2.E1.T3 D:\CppProjects\S2.E1.T3\cmake-build-debug D:\CppProjects\S2.E1.T3\cmake-build-debug D:\CppProjects\S2.E1.T3\cmake-build-debug\CMakeFiles\S2_E1_T3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/S2_E1_T3.dir/depend

