//
// Created by jimte on 2020-12-03.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include<SFML/Graphics.hpp>

#include "../containers/Player_Info.h"
#include "Textured_Object.h"
#include "Weapon.h"


class World;

class Player : public Character
{
public:
    Player(sf::Vector2f center, Player_Info &player_info);

    bool update(const sf::Time &delta, World &world) override;

    void render(sf::RenderWindow &window) override;

    Player_Info& player_info;

private:
    void apply_upgrades();
    void move_player(sf::Time delta, World &world);
    void jump(sf::Time delta);
    void fall(sf::Time delta, World &world);
    void handle_collision(World &world);
    void handle_jump_input();
    void handle_drop();
    void handle_inertia(sf::Time delta);
    void handle_horizontal_move(sf::Time delta, World &world);
    void handle_weapon(const sf::Time &delta, World &world);
    bool still_alive();
    void handle_animation();

    enum Player_State{
        standing,
        jumping,
        falling
    };

    Player_State player_state;
    // Player states:
    // 0: Standing
    // 1: Jumping
    // 2: Falling

    bool off_platform;
    float drop_margin;
    float vertical_duration;
    float horizontal_duration;
    float jump_start;
    bool inertia;
    bool moved_last_update;
    bool facing_right;

    bool jump_pressed;
    int jump_count;
    int max_jumps;
    float run_speed;

    float x_at_last_frame;
    std::vector<int> frame_numbers;

    Weapon weapon;
};


#endif //MAIN_CPP_PLAYER_H
