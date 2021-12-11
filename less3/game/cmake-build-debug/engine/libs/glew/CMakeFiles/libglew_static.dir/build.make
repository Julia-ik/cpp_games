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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/175/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/175/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lilu/lilu/cpp_games/cpp_games/less3/game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug

# Include any dependencies generated for this target.
include engine/libs/glew/CMakeFiles/libglew_static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include engine/libs/glew/CMakeFiles/libglew_static.dir/compiler_depend.make

# Include the progress variables for this target.
include engine/libs/glew/CMakeFiles/libglew_static.dir/progress.make

# Include the compile flags for this target's objects.
include engine/libs/glew/CMakeFiles/libglew_static.dir/flags.make

engine/libs/glew/CMakeFiles/libglew_static.dir/src/glew.c.o: engine/libs/glew/CMakeFiles/libglew_static.dir/flags.make
engine/libs/glew/CMakeFiles/libglew_static.dir/src/glew.c.o: ../engine/libs/glew/src/glew.c
engine/libs/glew/CMakeFiles/libglew_static.dir/src/glew.c.o: engine/libs/glew/CMakeFiles/libglew_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object engine/libs/glew/CMakeFiles/libglew_static.dir/src/glew.c.o"
	cd /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/engine/libs/glew && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT engine/libs/glew/CMakeFiles/libglew_static.dir/src/glew.c.o -MF CMakeFiles/libglew_static.dir/src/glew.c.o.d -o CMakeFiles/libglew_static.dir/src/glew.c.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/libs/glew/src/glew.c

engine/libs/glew/CMakeFiles/libglew_static.dir/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libglew_static.dir/src/glew.c.i"
	cd /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/engine/libs/glew && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/libs/glew/src/glew.c > CMakeFiles/libglew_static.dir/src/glew.c.i

engine/libs/glew/CMakeFiles/libglew_static.dir/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libglew_static.dir/src/glew.c.s"
	cd /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/engine/libs/glew && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/libs/glew/src/glew.c -o CMakeFiles/libglew_static.dir/src/glew.c.s

# Object files for target libglew_static
libglew_static_OBJECTS = \
"CMakeFiles/libglew_static.dir/src/glew.c.o"

# External object files for target libglew_static
libglew_static_EXTERNAL_OBJECTS =

engine/libs/glew/libglewd.a: engine/libs/glew/CMakeFiles/libglew_static.dir/src/glew.c.o
engine/libs/glew/libglewd.a: engine/libs/glew/CMakeFiles/libglew_static.dir/build.make
engine/libs/glew/libglewd.a: engine/libs/glew/CMakeFiles/libglew_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglewd.a"
	cd /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/engine/libs/glew && $(CMAKE_COMMAND) -P CMakeFiles/libglew_static.dir/cmake_clean_target.cmake
	cd /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/engine/libs/glew && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libglew_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/libs/glew/CMakeFiles/libglew_static.dir/build: engine/libs/glew/libglewd.a
.PHONY : engine/libs/glew/CMakeFiles/libglew_static.dir/build

engine/libs/glew/CMakeFiles/libglew_static.dir/clean:
	cd /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/engine/libs/glew && $(CMAKE_COMMAND) -P CMakeFiles/libglew_static.dir/cmake_clean.cmake
.PHONY : engine/libs/glew/CMakeFiles/libglew_static.dir/clean

engine/libs/glew/CMakeFiles/libglew_static.dir/depend:
	cd /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilu/lilu/cpp_games/cpp_games/less3/game /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/libs/glew /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/engine/libs/glew /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/engine/libs/glew/CMakeFiles/libglew_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/libs/glew/CMakeFiles/libglew_static.dir/depend

