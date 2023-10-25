#include "Game.h"
#include "GamePlayState.h"

GamePlayState::GamePlayState(sf::RenderWindow& window)
    : GameState(window)
{
    game = new Game();
}

GamePlayState::~GamePlayState()
{
    delete game;
}

void GamePlayState::update()
{

}

void GamePlayState::render(sf::RenderWindow& window)
{

}
