# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/137/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/137/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marku849/Projects/TDP005/tdp005-backup/project_ghost

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project_ghost.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project_ghost.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_ghost.dir/flags.make

CMakeFiles/project_ghost.dir/main.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project_ghost.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/main.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/main.cpp

CMakeFiles/project_ghost.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/main.cpp > CMakeFiles/project_ghost.dir/main.cpp.i

CMakeFiles/project_ghost.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/main.cpp -o CMakeFiles/project_ghost.dir/main.cpp.s

CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.o: ../game_objects/Game_Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Game_Object.cpp

CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Game_Object.cpp > CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.i

CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Game_Object.cpp -o CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.s

CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.o: ../game_objects/Textured_Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Textured_Object.cpp

CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Textured_Object.cpp > CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.i

CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Textured_Object.cpp -o CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.s

CMakeFiles/project_ghost.dir/game_objects/Player.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/game_objects/Player.cpp.o: ../game_objects/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project_ghost.dir/game_objects/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/game_objects/Player.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Player.cpp

CMakeFiles/project_ghost.dir/game_objects/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/game_objects/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Player.cpp > CMakeFiles/project_ghost.dir/game_objects/Player.cpp.i

CMakeFiles/project_ghost.dir/game_objects/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/game_objects/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Player.cpp -o CMakeFiles/project_ghost.dir/game_objects/Player.cpp.s

CMakeFiles/project_ghost.dir/managers/World.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/managers/World.cpp.o: ../managers/World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project_ghost.dir/managers/World.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/managers/World.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/managers/World.cpp

CMakeFiles/project_ghost.dir/managers/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/managers/World.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/managers/World.cpp > CMakeFiles/project_ghost.dir/managers/World.cpp.i

CMakeFiles/project_ghost.dir/managers/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/managers/World.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/managers/World.cpp -o CMakeFiles/project_ghost.dir/managers/World.cpp.s

CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.o: ../managers/Texture_Manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/managers/Texture_Manager.cpp

CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/managers/Texture_Manager.cpp > CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.i

CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/managers/Texture_Manager.cpp -o CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.s

CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.o: ../game_objects/Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Enemy.cpp

CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Enemy.cpp > CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.i

CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Enemy.cpp -o CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.s

CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.o: ../game_objects/Weapon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Weapon.cpp

CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Weapon.cpp > CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.i

CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Weapon.cpp -o CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.s

CMakeFiles/project_ghost.dir/states/State.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/states/State.cpp.o: ../states/State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/project_ghost.dir/states/State.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/states/State.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/states/State.cpp

CMakeFiles/project_ghost.dir/states/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/states/State.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/states/State.cpp > CMakeFiles/project_ghost.dir/states/State.cpp.i

CMakeFiles/project_ghost.dir/states/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/states/State.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/states/State.cpp -o CMakeFiles/project_ghost.dir/states/State.cpp.s

CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.o: CMakeFiles/project_ghost.dir/flags.make
CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.o: ../game_objects/Projectile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.o -c /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Projectile.cpp

CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Projectile.cpp > CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.i

CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/game_objects/Projectile.cpp -o CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.s

# Object files for target project_ghost
project_ghost_OBJECTS = \
"CMakeFiles/project_ghost.dir/main.cpp.o" \
"CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.o" \
"CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.o" \
"CMakeFiles/project_ghost.dir/game_objects/Player.cpp.o" \
"CMakeFiles/project_ghost.dir/managers/World.cpp.o" \
"CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.o" \
"CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.o" \
"CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.o" \
"CMakeFiles/project_ghost.dir/states/State.cpp.o" \
"CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.o"

# External object files for target project_ghost
project_ghost_EXTERNAL_OBJECTS =

project_ghost: CMakeFiles/project_ghost.dir/main.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/game_objects/Game_Object.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/game_objects/Textured_Object.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/game_objects/Player.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/managers/World.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/managers/Texture_Manager.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/game_objects/Enemy.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/game_objects/Weapon.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/states/State.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/game_objects/Projectile.cpp.o
project_ghost: CMakeFiles/project_ghost.dir/build.make
project_ghost: /usr/lib/x86_64-linux-gnu/libsfml-network.so.2.5.1
project_ghost: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
project_ghost: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
project_ghost: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
project_ghost: CMakeFiles/project_ghost.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable project_ghost"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_ghost.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_ghost.dir/build: project_ghost

.PHONY : CMakeFiles/project_ghost.dir/build

CMakeFiles/project_ghost.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_ghost.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_ghost.dir/clean

CMakeFiles/project_ghost.dir/depend:
	cd /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marku849/Projects/TDP005/tdp005-backup/project_ghost /home/marku849/Projects/TDP005/tdp005-backup/project_ghost /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug /home/marku849/Projects/TDP005/tdp005-backup/project_ghost/cmake-build-debug/CMakeFiles/project_ghost.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_ghost.dir/depend

