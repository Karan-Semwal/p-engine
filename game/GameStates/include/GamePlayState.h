#pragma once
#include "GameState.h"

class Game;

class GamePlayState : public GameState
{
public:
    GamePlayState(sf::RenderWindow &window, int levelNumber = 1);
    ~GamePlayState();

    GameState *update() override;
    void render(sf::RenderWindow &window) override;

private:
    Game *game;
};