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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib

# Include any dependencies generated for this target.
include CMakeFiles/dynamic-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dynamic-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dynamic-lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dynamic-lib.dir/flags.make

CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o: CMakeFiles/dynamic-lib.dir/flags.make
CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o: library-dynamic.cpp
CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o: CMakeFiles/dynamic-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o -MF CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o.d -o CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib/library-dynamic.cpp

CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib/library-dynamic.cpp > CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.i

CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib/library-dynamic.cpp -o CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.s

# Object files for target dynamic-lib
dynamic__lib_OBJECTS = \
"CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o"

# External object files for target dynamic-lib
dynamic__lib_EXTERNAL_OBJECTS =

libdynamic-lib.so: CMakeFiles/dynamic-lib.dir/library-dynamic.cpp.o
libdynamic-lib.so: CMakeFiles/dynamic-lib.dir/build.make
libdynamic-lib.so: CMakeFiles/dynamic-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libdynamic-lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dynamic-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dynamic-lib.dir/build: libdynamic-lib.so
.PHONY : CMakeFiles/dynamic-lib.dir/build

CMakeFiles/dynamic-lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dynamic-lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dynamic-lib.dir/clean

CMakeFiles/dynamic-lib.dir/depend:
	cd /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/dynamic_lib/CMakeFiles/dynamic-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dynamic-lib.dir/depend

