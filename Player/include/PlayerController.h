#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayerState.h"
#include "CollisionSide.h"
#include "Tilemap.h"

class PlayerController
{
public:
    PlayerController();
    ~PlayerController() {}

    bool canMove(const sf::Vector2f& pos, Tilemap& map);

    void update(Player& player, Tilemap& map);

private:
    float m_velocityLerpValue = 3.0f;
    sf::Vector2f m_currentVelocity;
    sf::Vector2f m_velocity;
};