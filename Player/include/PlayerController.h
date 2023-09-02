#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayerState.h"
#include "CollisionSide.h"

class PlayerController
{
public:
    PlayerController()  {}
    ~PlayerController() {}

    void update(Player& player, CollisionSide& collSide);
};