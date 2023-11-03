#include "Game.h"
#include "GamePlayState.h"
#include "GamePauseState.h"

GamePlayState::GamePlayState(sf::RenderWindow& window)
    : GameState(window)
{
    sf::Texture texture;
    button = new Button{ *this->m_window, texture, 100, 100, 100, 50 }; // DBG
    button->getButtonObject().setFillColor(sf::Color::Red);
    game = new Game();
    std::cout << "--------- Game Play State Created! ---------\n"; // DBG
}

GamePlayState::~GamePlayState()
{
    delete game;
    std::cout << "--------- Game Play State Destroyed! ---------\n"; // DBG
}

GameState* GamePlayState::update()
{
    game->update();
    // Pause the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        // passing this object to new GamePauseState
        return new GamePauseState{ *this->m_window, this };
        delete this;
    }
    if (button->isClicked()) {
        std::cout << "Button Clicked!!!!!!\n"; // DBG
    }
    return nullptr;
}

void GamePlayState::render(sf::RenderWindow& window)
{
    game->render(window);
    button->render(window);
}
