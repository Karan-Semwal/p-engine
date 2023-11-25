#include <iostream>
#include "MainMenuState.h"
#include "GamePlayState.h"
#include "GameLevelsState.h"
#include "pengine.h"

MainMenuState::MainMenuState(sf::RenderWindow &window)
    : GameState(window),
      m_playButtonTextureAddress{nullptr},
      m_exitButtonTextureAddress{nullptr}
{
    m_background = new sf::RectangleShape{};
    m_play = new Button{*this->m_window, *m_playButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y - 50, 150, 75};
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
    // m_background->setFillColor(randomColor());
    m_background->setTexture(&TextureManager::getInstance().get_backg_texture(1)); // DBG
    m_exit->getButtonObject().setFillColor(sf::Color::Cyan);
    m_play->getButtonObject().setTexture(&TextureManager::getInstance().get_playButton_texture());
    // m_play->getButtonObject().setOutlineColor(sf::Color::Green); // DBG
    // m_play->getButtonObject().setOutlineThickness(3.f);
}

GameState *MainMenuState::update()
{
    // Switch to Game Play State
    if (m_play->isClicked())
    {
        // if game does not have levels:
        //return new GamePlayState{*this->m_window};
        
        auto window = this->m_window;
        delete this;
        return new GameLevelsState{*window};
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
