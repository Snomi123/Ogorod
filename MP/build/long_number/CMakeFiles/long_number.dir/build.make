# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/igormajorov/Desktop/Ogorod/MP/projects/dz4.long_number

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/igormajorov/Desktop/Ogorod/MP/build

# Include any dependencies generated for this target.
include long_number/CMakeFiles/long_number.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include long_number/CMakeFiles/long_number.dir/compiler_depend.make

# Include the progress variables for this target.
include long_number/CMakeFiles/long_number.dir/progress.make

# Include the compile flags for this target's objects.
include long_number/CMakeFiles/long_number.dir/flags.make

long_number/CMakeFiles/long_number.dir/codegen:
.PHONY : long_number/CMakeFiles/long_number.dir/codegen

long_number/CMakeFiles/long_number.dir/long_number.cpp.o: long_number/CMakeFiles/long_number.dir/flags.make
long_number/CMakeFiles/long_number.dir/long_number.cpp.o: /Users/igormajorov/Desktop/Ogorod/MP/projects/dz4.long_number/long_number/long_number.cpp
long_number/CMakeFiles/long_number.dir/long_number.cpp.o: long_number/CMakeFiles/long_number.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/igormajorov/Desktop/Ogorod/MP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object long_number/CMakeFiles/long_number.dir/long_number.cpp.o"
	cd /Users/igormajorov/Desktop/Ogorod/MP/build/long_number && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT long_number/CMakeFiles/long_number.dir/long_number.cpp.o -MF CMakeFiles/long_number.dir/long_number.cpp.o.d -o CMakeFiles/long_number.dir/long_number.cpp.o -c /Users/igormajorov/Desktop/Ogorod/MP/projects/dz4.long_number/long_number/long_number.cpp

long_number/CMakeFiles/long_number.dir/long_number.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/long_number.dir/long_number.cpp.i"
	cd /Users/igormajorov/Desktop/Ogorod/MP/build/long_number && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/igormajorov/Desktop/Ogorod/MP/projects/dz4.long_number/long_number/long_number.cpp > CMakeFiles/long_number.dir/long_number.cpp.i

long_number/CMakeFiles/long_number.dir/long_number.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/long_number.dir/long_number.cpp.s"
	cd /Users/igormajorov/Desktop/Ogorod/MP/build/long_number && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/igormajorov/Desktop/Ogorod/MP/projects/dz4.long_number/long_number/long_number.cpp -o CMakeFiles/long_number.dir/long_number.cpp.s

# Object files for target long_number
long_number_OBJECTS = \
"CMakeFiles/long_number.dir/long_number.cpp.o"

# External object files for target long_number
long_number_EXTERNAL_OBJECTS =

long_number/liblong_number.a: long_number/CMakeFiles/long_number.dir/long_number.cpp.o
long_number/liblong_number.a: long_number/CMakeFiles/long_number.dir/build.make
long_number/liblong_number.a: long_number/CMakeFiles/long_number.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/igormajorov/Desktop/Ogorod/MP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblong_number.a"
	cd /Users/igormajorov/Desktop/Ogorod/MP/build/long_number && $(CMAKE_COMMAND) -P CMakeFiles/long_number.dir/cmake_clean_target.cmake
	cd /Users/igormajorov/Desktop/Ogorod/MP/build/long_number && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/long_number.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
long_number/CMakeFiles/long_number.dir/build: long_number/liblong_number.a
.PHONY : long_number/CMakeFiles/long_number.dir/build

long_number/CMakeFiles/long_number.dir/clean:
	cd /Users/igormajorov/Desktop/Ogorod/MP/build/long_number && $(CMAKE_COMMAND) -P CMakeFiles/long_number.dir/cmake_clean.cmake
.PHONY : long_number/CMakeFiles/long_number.dir/clean

long_number/CMakeFiles/long_number.dir/depend:
	cd /Users/igormajorov/Desktop/Ogorod/MP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/igormajorov/Desktop/Ogorod/MP/projects/dz4.long_number /Users/igormajorov/Desktop/Ogorod/MP/projects/dz4.long_number/long_number /Users/igormajorov/Desktop/Ogorod/MP/build /Users/igormajorov/Desktop/Ogorod/MP/build/long_number /Users/igormajorov/Desktop/Ogorod/MP/build/long_number/CMakeFiles/long_number.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : long_number/CMakeFiles/long_number.dir/depend

