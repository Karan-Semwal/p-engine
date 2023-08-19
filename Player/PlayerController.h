#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayerState.h"

class PlayerController
{
public:
    PlayerController()  {}
    ~PlayerController() {}

    void update(Player& player);
};