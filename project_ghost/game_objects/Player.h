//
// Created by jimte on 2020-12-03.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "Textured_Object.h"
#include "Weapon.h"
#include "../managers/World.h"

class Player : public Character
{
public:
    Player(sf::Vector2f center, std::string const &texture_name, int health,
           int damage, int max_jumps, float run_speed, float fire_rate);

    bool update(const sf::Time &delta, World &world) override;

    void render(sf::RenderWindow &window) override;

private:
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


    int player_state;
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
    const int MAX_JUMPS;
    float run_speed;

    Weapon weapon;
};


#endif //MAIN_CPP_PLAYER_H
