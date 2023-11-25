#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Utils/Timer.h"

class Animator
{
public:
    Animator() = delete;
    Animator(sf::RectangleShape& object, sf::Texture& spriteSheet, int c, int r, float ft);
    Animator(sf::RectangleShape& object, sf::Texture& spriteSheet, int c, int r, const sf::Vector2f& pos, float ft);
    virtual ~Animator() { }

    void setPosition(sf::Vector2f& pos);
    void setScale(float scaleX, float scaleY);

    virtual void update();
    void render(sf::RenderWindow& window);

public:
    bool isAlive = true;
    
protected:
    int columns;
    int rows;
    int currentFrame;

    // speed of animation
    float frameTime;
    Timer m_timer;

    sf::RectangleShape&  sprite;
    sf::Texture*         texture;
    sf::Vector2f         position;
};