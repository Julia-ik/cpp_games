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
CMAKE_SOURCE_DIR = /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs

# Include any dependencies generated for this target.
include CMakeFiles/static-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/static-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/static-lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/static-lib.dir/flags.make

CMakeFiles/static-lib.dir/library.cpp.o: CMakeFiles/static-lib.dir/flags.make
CMakeFiles/static-lib.dir/library.cpp.o: library.cpp
CMakeFiles/static-lib.dir/library.cpp.o: CMakeFiles/static-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/static-lib.dir/library.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/static-lib.dir/library.cpp.o -MF CMakeFiles/static-lib.dir/library.cpp.o.d -o CMakeFiles/static-lib.dir/library.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs/library.cpp

CMakeFiles/static-lib.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static-lib.dir/library.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs/library.cpp > CMakeFiles/static-lib.dir/library.cpp.i

CMakeFiles/static-lib.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static-lib.dir/library.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs/library.cpp -o CMakeFiles/static-lib.dir/library.cpp.s

# Object files for target static-lib
static__lib_OBJECTS = \
"CMakeFiles/static-lib.dir/library.cpp.o"

# External object files for target static-lib
static__lib_EXTERNAL_OBJECTS =

libstatic-lib.a: CMakeFiles/static-lib.dir/library.cpp.o
libstatic-lib.a: CMakeFiles/static-lib.dir/build.make
libstatic-lib.a: CMakeFiles/static-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libstatic-lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/static-lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/static-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/static-lib.dir/build: libstatic-lib.a
.PHONY : CMakeFiles/static-lib.dir/build

CMakeFiles/static-lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/static-lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/static-lib.dir/clean

CMakeFiles/static-lib.dir/depend:
	cd /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs /home/lilu/lilu/cpp_games/cpp_games/hw_2/libs/static_libs/CMakeFiles/static-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/static-lib.dir/depend

