#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "Player/PlayerState.h"
#include "Collision/CollisionSide.h"
#include "Map/Tilemap.h"
#include "Utils/Util.h"

class PlayerController
{
public:
    PlayerController();
    ~PlayerController() {}

    bool canMove(const sf::Vector2f& pos, Tilemap& map);
    void update(Player& player, Tilemap& map, sf::Event& event);
    void gravity(Player& player, Tilemap& map);

private:
    float m_velocityLerpValue = 1.5f;
    sf::Vector2f m_currentVelocity;
    sf::Vector2f m_velocity;

    bool isInAir = true;

    float GRAVITY            = 0.0f;
    float GRAVITY_LIMIT      = 4.f;
    float GRAVITY_LERP_VALUE = 0.1f;
};
