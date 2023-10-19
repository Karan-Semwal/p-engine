#include "GamePlayState.h"
#include "Game.h"

GamePlayState::GamePlayState()
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
