#pragma once
#include "GameState.h"

class Button; // DBG

class Game;

class GamePlayState : public GameState
{
public:
    GamePlayState(sf::RenderWindow& window);
    ~GamePlayState();

    GameState* update() override;
    void render(sf::RenderWindow& window) override;

private:
    Button* button; // DBG
    Game* game;
};