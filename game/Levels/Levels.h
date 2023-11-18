#pragma once
#include "pengine.h"

// number of rows and columns in Game Level State
constexpr inline int ROW_COUNT    = 4; 
constexpr inline int COLUMN_COUNT = 4;

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