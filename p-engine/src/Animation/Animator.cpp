#include "Animator.h"

Animator::Animator(sf::RectangleShape& object, sf::Texture& spriteSheet, int c, int r, float ft)
    : texture(&spriteSheet),
      columns(c),
      rows   (r),
      currentFrame(0),
      frameTime(ft),
      sprite(object),
      m_timer()
{
    position = sprite.getPosition();
    this->setPosition(position);
    m_timer.start();
    sprite.setSize({64.f, 64.f});
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, texture->getSize().x / columns, texture->getSize().y / rows));
 
    sf::Vector2f centre(sprite.getTextureRect().width / 2.f, sprite.getTextureRect().height / 2.f);
    sprite.setOrigin(centre);
}

Animator::Animator(sf::RectangleShape& object, sf::Texture& spriteSheet, int c, int r, const sf::Vector2f& pos, float ft)
    : texture(&spriteSheet),
      position(pos),
      columns(c),
      rows   (r),
      currentFrame(0),
      frameTime(ft),
      sprite(object),
      m_timer()
{
    m_timer.start();
    sprite.setSize({64.f, 64.f});
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, texture->getSize().x / columns, texture->getSize().y / rows));
 
    sf::Vector2f centre(sprite.getTextureRect().width / 2.f, sprite.getTextureRect().height / 2.f);
    sprite.setOrigin(centre);
    this->setPosition(position);
}

void Animator::update()
{
    if (this->isAlive) 
    {
        if (m_timer.getElapsedTime() >= frameTime) {
            currentFrame++;
            m_timer.reset();

            if (currentFrame >= columns) {
                currentFrame = 0;
                isAlive = false;
                return;
            }

            int frameX = currentFrame % columns;
            int frameY = currentFrame / columns; // to switch between rows

            sprite.setTextureRect(sf::IntRect(
                frameX * sprite.getTextureRect().width,
                frameY * sprite.getTextureRect().height,
                sprite.getTextureRect().width,
                sprite.getTextureRect().height)
            );
        }
        m_timer.update();
    }
}

void Animator::setPosition(sf::Vector2f& pos)
{
    sprite.setPosition(pos);
}

void Animator::setScale(float scaleX, float scaleY)
{
    sprite.setScale(scaleX, scaleY);
}

void Animator:: render(sf::RenderWindow& window)
{
    window.draw(sprite);
}