#pragma once
#include "pengine.h"

constexpr inline int TOTAL_NUMBER_OF_LEVELS = 3;

struct LevelButton : public Button
{
    LevelButton() = delete;
    LevelButton(sf::RenderWindow& window, float size, int levelNumber, sf::Texture& texture) 
        : Button(window, texture, size, size, size, size),
            LevelNumber{levelNumber}
    {
    }
    ~LevelButton() {}

    sf::Vector2f getPos() { return getButtonObject().getPosition(); }
    void setPos(const sf::Vector2f& pos) { getButtonObject().setPosition(pos); }

    int LevelNumber;
};