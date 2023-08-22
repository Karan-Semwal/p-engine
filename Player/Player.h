#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "PlayerState.h"

// Forward declaration
class PlayerAnimator;
class PlayerController;

class Player
{
public:
    Player();
    ~Player();
    void initialTexture();
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);
    sf::Sprite& getPlayer();
    sf::Vector2f& getVelocity();
    void update();
    void render(sf::RenderWindow& window);

public:
    PlayerState           pstate;
    PlayerFacingDirection pfacingDirection;

private:
    sf::Sprite     m_player;
    sf::Vector2f   m_veloctiy;
    PlayerAnimator*   m_animator;
    PlayerController* m_controller;
};