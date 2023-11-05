#include "Game.h"
#include "GamePlayState.h"
#include "GamePauseState.h"
#include "GameOverState.h"

GamePlayState::GamePlayState(sf::RenderWindow &window)
    : GameState(window)
{
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
        // IMP: detach the sf::View attached on Player by Game class
        this->m_window->setView(this->m_window->getDefaultView());
        // passing this object to new GamePauseState
        return new GamePauseState{*this->m_window, this};
    }

    // if GAME OVER:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        // IMP: detach the sf::View attached on Player by Game class
        // IMP: Store store m_window before deleting this object
        auto window = this->m_window;
        window->setView(window->getDefaultView());
        // delete the current GAME OBJECT
        delete this;
        // Switch to Game Over State
        return new GameOverState{*window};
    }
    return nullptr;
}

void GamePlayState::render(sf::RenderWindow &window)
{
    game->render(window);
}
