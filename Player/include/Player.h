#pragma once
#include <SFML/Graphics.hpp>
#include "Tilemap.h"
#include "PlayerState.h"
#include "TextureManager.h"

// Forward declaration
class PlayerAnimator;
class PlayerController;
class PlayerCollider;

class Player
{
public:
    Player();
    ~Player();
    void initTexture();
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);
    sf::Sprite& getObject();
    sf::Vector2f& getVelocity();
    void setVelocity(const sf::Vector2f& vel);
    void update(Tilemap& map);
    void render(sf::RenderWindow& window);

public:
    PlayerState           pstate;
    PlayerFacingDirection pfacingDirection;

private:
    sf::Sprite     m_player;
    sf::Vector2f   m_veloctiy;
    
    PlayerController* m_controller; // handle player input
    PlayerCollider*   m_collider;   // handle player collisions
    PlayerAnimator*   m_animator;   // handle player animations
};