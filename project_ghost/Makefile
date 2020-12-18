CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17


# type 'make all' or 'gmake all' to build everything
all: build/ghost_game

build/ghost_game: main.o game_objects/Game_Object.o game_objects/Textured_Object.o game_objects/Player.o managers/World.o managers/Texture_Manager.o game_objects/Enemy.o game_objects/Weapon.o states/State.o game_objects/Projectile.o states/Game_State.o containers/Upgrade.o containers/Player_Info.o game_objects/Money.o game_objects/Weapon.o managers/Sound_Manager.o game_objects/Upgrade_Pillar.o game_objects/Door.o game_objects/Hud.o states/Menu_State.o -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system

	$(CXX) $^ $(LDFLAGS) -o $@

# to build an *.o file we need corresponding *.cc file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

# to clean up compiler-generated files
clean:
	\rm -f *.o *.stackdump ghost_game
