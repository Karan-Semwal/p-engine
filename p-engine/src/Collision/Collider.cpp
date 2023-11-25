#include "Collision/Collider.h"

Collider::Collider(sf::RectangleShape& rect)
    : m_rectangle(&rect)
{
    m_circle = nullptr;
    m_sprite = nullptr;
}

Collider::Collider(sf::CircleShape& circle)
    : m_circle(&circle)
{
    m_sprite    = nullptr;
    m_rectangle = nullptr;
}

Collider::Collider(sf::Sprite& sprite)
    : m_sprite(&sprite)
{
    m_circle    = nullptr;
    m_rectangle = nullptr;
}

void* Collider::getObject() const 
{
    if (isCircle && !isRectangle && !isSprite) {
        return m_circle;
    }
    else if (!isCircle && isRectangle && !isSprite) {
        return m_rectangle;
    }
    else {
        return m_sprite;
    }
}

bool Collider::isColliding(sf::RectangleShape& rect)
{
    if (isCircle && !isRectangle && !isSprite) {
        return m_circle->getGlobalBounds().intersects(rect.getGlobalBounds());
    }
    else if (!isCircle && isRectangle && !isSprite) {
        return m_rectangle->getGlobalBounds().intersects(rect.getGlobalBounds());
    }
    else {
        return m_sprite->getGlobalBounds().intersects(rect.getGlobalBounds());
    }
}

bool Collider::isColliding(sf::CircleShape& circle)
{
    if (isCircle && !isRectangle && !isSprite) {
        return m_circle->getGlobalBounds().intersects(circle.getGlobalBounds());
    }
    else if (!isCircle && isRectangle && !isSprite) {
        return m_rectangle->getGlobalBounds().intersects(circle.getGlobalBounds());
    }
    else {
        return m_sprite->getGlobalBounds().intersects(circle.getGlobalBounds());
    }
}

bool Collider::isColliding(sf::Sprite& sprite)
{
    if (isCircle && !isRectangle && !isSprite) {
        return m_circle->getGlobalBounds().intersects(sprite.getGlobalBounds());
    }
    else if (!isCircle && isRectangle && !isSprite) {
        return m_rectangle->getGlobalBounds().intersects(sprite.getGlobalBounds());
    }
    else {
        return m_sprite->getGlobalBounds().intersects(sprite.getGlobalBounds());
    }
}   

    