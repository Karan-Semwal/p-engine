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

GameState* GamePlayState::update()
{
    std::cout << "Inside GamePlayState\n"; // DBG
    return nullptr;
}

void GamePlayState::render(sf::RenderWindow& window)
{

}
