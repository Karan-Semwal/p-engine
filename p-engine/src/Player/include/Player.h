#pragma once
#include <SFML/Graphics.hpp>
#include "Tilemap.h"
#include "PlayerState.h"
#include "TextureManager.h"
#include "Hitbox.h"

// Forward declaration
class PlayerAnimator;
class PlayerController;

class Player
{
public:
    Player();
    ~Player();
    void initTexture();
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);
    sf::RectangleShape& getObject();
    sf::Vector2f& getVelocity();
    void setVelocity(const sf::Vector2f& vel);
    void update(Tilemap& map, sf::Event& event);
    void render(sf::RenderWindow& window);

public:
    Hitbox                 hitbox;
    PlayerState            pstate;
    PlayerFacingDirection  pfacingDirection;

private:
    sf::Vector2f           m_size;
    sf::RectangleShape     m_player;
    sf::Vector2f           m_veloctiy;
    
    PlayerController* m_controller; // handle player input
    PlayerAnimator*   m_animator;   // handle player animations
};