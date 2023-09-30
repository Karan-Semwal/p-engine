#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
    Collider() = delete;
    Collider(sf::RectangleShape& rect);
    Collider(sf::CircleShape& circle);
    Collider(sf::Sprite& sprite);
    virtual ~Collider() { }

    virtual bool isColliding(sf::RectangleShape& rect);
    virtual bool isColliding(sf::CircleShape& circle);
    virtual bool isColliding(sf::Sprite& sprite);    
    void* getObject() const;

    virtual void onColliding() = 0;

public:
    bool isCircle    = false;
    bool isSprite    = false;
    bool isRectangle = false;

private:
    sf::Sprite*         m_sprite;
    sf::CircleShape*    m_circle;
    sf::RectangleShape* m_rectangle;
};