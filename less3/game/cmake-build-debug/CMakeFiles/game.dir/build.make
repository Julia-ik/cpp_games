# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lilu/lilu/cpp_games/cpp_games/less3/game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/main.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/main.cpp

CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/main.cpp > CMakeFiles/game.dir/main.cpp.i

CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/main.cpp -o CMakeFiles/game.dir/main.cpp.s

CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.o: ../engine/SRC/SDL/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/Model.cpp

CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/Model.cpp > CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.i

CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/Model.cpp -o CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.s

CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.o: ../engine/SRC/SDL/Model_head.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/Model_head.cpp

CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/Model_head.cpp > CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.i

CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/Model_head.cpp -o CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.s

CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.o: ../engine/SRC/SDL/f_triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/f_triangle.cpp

CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/f_triangle.cpp > CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.i

CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/f_triangle.cpp -o CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.s

CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.o: ../engine/SRC/SDL/v_point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/v_point.cpp

CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/v_point.cpp > CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.i

CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SDL/v_point.cpp -o CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.s

CMakeFiles/game.dir/engine/Mesh.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/Mesh.cpp.o: ../engine/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/engine/Mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/Mesh.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/Mesh.cpp

CMakeFiles/game.dir/engine/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/Mesh.cpp > CMakeFiles/game.dir/engine/Mesh.cpp.i

CMakeFiles/game.dir/engine/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/Mesh.cpp -o CMakeFiles/game.dir/engine/Mesh.cpp.s

CMakeFiles/game.dir/engine/SRC/Shader.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/Shader.cpp.o: ../engine/SRC/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/engine/SRC/Shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/Shader.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Shader.cpp

CMakeFiles/game.dir/engine/SRC/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Shader.cpp > CMakeFiles/game.dir/engine/SRC/Shader.cpp.i

CMakeFiles/game.dir/engine/SRC/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Shader.cpp -o CMakeFiles/game.dir/engine/SRC/Shader.cpp.s

CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.o: ../engine/SRC/Bitmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Bitmap.cpp

CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Bitmap.cpp > CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.i

CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Bitmap.cpp -o CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.s

CMakeFiles/game.dir/engine/SRC/Texture.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/Texture.cpp.o: ../engine/SRC/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/game.dir/engine/SRC/Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/Texture.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Texture.cpp

CMakeFiles/game.dir/engine/SRC/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Texture.cpp > CMakeFiles/game.dir/engine/SRC/Texture.cpp.i

CMakeFiles/game.dir/engine/SRC/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/Texture.cpp -o CMakeFiles/game.dir/engine/SRC/Texture.cpp.s

CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.o: ../engine/SRC/ResourceLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/ResourceLoader.cpp

CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/ResourceLoader.cpp > CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.i

CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/ResourceLoader.cpp -o CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.s

CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.o: ../engine/SRC/SpriteRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SpriteRenderer.cpp

CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SpriteRenderer.cpp > CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.i

CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/SpriteRenderer.cpp -o CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.s

CMakeFiles/game.dir/engine/SRC/EventManager.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/engine/SRC/EventManager.cpp.o: ../engine/SRC/EventManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/game.dir/engine/SRC/EventManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/engine/SRC/EventManager.cpp.o -c /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/EventManager.cpp

CMakeFiles/game.dir/engine/SRC/EventManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/engine/SRC/EventManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/EventManager.cpp > CMakeFiles/game.dir/engine/SRC/EventManager.cpp.i

CMakeFiles/game.dir/engine/SRC/EventManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/engine/SRC/EventManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilu/lilu/cpp_games/cpp_games/less3/game/engine/SRC/EventManager.cpp -o CMakeFiles/game.dir/engine/SRC/EventManager.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/main.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.o" \
"CMakeFiles/game.dir/engine/Mesh.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/Shader.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/Texture.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.o" \
"CMakeFiles/game.dir/engine/SRC/EventManager.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/main.cpp.o
game: CMakeFiles/game.dir/engine/SRC/SDL/Model.cpp.o
game: CMakeFiles/game.dir/engine/SRC/SDL/Model_head.cpp.o
game: CMakeFiles/game.dir/engine/SRC/SDL/f_triangle.cpp.o
game: CMakeFiles/game.dir/engine/SRC/SDL/v_point.cpp.o
game: CMakeFiles/game.dir/engine/Mesh.cpp.o
game: CMakeFiles/game.dir/engine/SRC/Shader.cpp.o
game: CMakeFiles/game.dir/engine/SRC/Bitmap.cpp.o
game: CMakeFiles/game.dir/engine/SRC/Texture.cpp.o
game: CMakeFiles/game.dir/engine/SRC/ResourceLoader.cpp.o
game: CMakeFiles/game.dir/engine/SRC/SpriteRenderer.cpp.o
game: CMakeFiles/game.dir/engine/SRC/EventManager.cpp.o
game: CMakeFiles/game.dir/build.make
game: engine/libengine.a
game: engine/libs/SDL2/libSDL2maind.a
game: engine/libs/SDL2/libSDL2d.a
game: engine/libs/glew/libglewd.a
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilu/lilu/cpp_games/cpp_games/less3/game /home/lilu/lilu/cpp_games/cpp_games/less3/game /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug /home/lilu/lilu/cpp_games/cpp_games/less3/game/cmake-build-debug/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

