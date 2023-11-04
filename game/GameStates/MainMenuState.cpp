#include <iostream>
#include "MainMenuState.h"
#include "GamePlayState.h"
#include "pengine.h"

MainMenuState::MainMenuState(sf::RenderWindow &window)
    : GameState(window),
      m_playButtonTextureAddress{nullptr},
      m_exitButtonTextureAddress{nullptr}
{
    m_background = new sf::RectangleShape{};
    m_play = new Button{*this->m_window, *m_playButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y - 50, 100, 50};
    m_exit = new Button{*this->m_window, *m_exitButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y + 50, 100, 50};
    init();
}

MainMenuState::~MainMenuState()
{
    delete m_background;
    delete m_play;
    delete m_exit;
}

void MainMenuState::init()
{
    m_background->setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
    // Color
    m_background->setFillColor(randomColor());
    m_play->getButtonObject().setFillColor(sf::Color::Green);
    m_exit->getButtonObject().setFillColor(sf::Color::Cyan);
}

GameState *MainMenuState::update()
{
    // Switch to Game Play State
    if (m_play->isClicked())
    {
        return new GamePlayState{*this->m_window};
        delete this;
    }
    // Exit the application
    if (m_exit->isClicked())
    {
        std::cout << "Quit Game!\n";
    }
    return nullptr;
}

void MainMenuState::render(sf::RenderWindow &window)
{
    window.draw(*m_background);
    m_play->render(window);
    m_exit->render(window);
}
