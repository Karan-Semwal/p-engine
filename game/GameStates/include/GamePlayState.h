#pragma once
#include "GameState.h"

class Game;

class GamePlayState : public GameState
{
public:
    GamePlayState();
    ~GamePlayState();

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    Game* game;
};