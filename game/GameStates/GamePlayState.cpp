#include "Game.h"
#include "GamePlayState.h"
#include "GamePauseState.h"

GamePlayState::GamePlayState(sf::RenderWindow &window)
    : GameState(window)
{
    sf::Texture texture;
    game = new Game();
}

GamePlayState::~GamePlayState()
{
    delete game;
}

GameState *GamePlayState::update()
{
    game->update();
    // Switch to Game Pause State
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        // IMP: detach the sf::View attached by Game class for Player
        this->m_window->setView(this->m_window->getDefaultView());
        // passing this object to new GamePauseState
        return new GamePauseState{*this->m_window, this};
    }
    return nullptr;
}

void GamePlayState::render(sf::RenderWindow &window)
{
    game->render(window);
}
