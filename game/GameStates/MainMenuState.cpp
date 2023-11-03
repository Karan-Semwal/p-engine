#include <iostream>
#include "MainMenuState.h"
#include "GamePlayState.h"
#include "pengine.h"

MainMenuState::MainMenuState(sf::RenderWindow& window)
    : GameState(window),
      m_playButtonTextureAddress{ nullptr },
      m_exitButtonTextureAddress{ nullptr }
{
    sf::Texture texture; // DBG
    m_background = new sf::RectangleShape{};
    m_play = new Button{ *this->m_window, *m_playButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y - 50, 100, 50 };
    m_exit = new Button{ *this->m_window, *m_exitButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y + 50, 100, 50 };
    init();
    std::cout << "--------- Main Menu State Created! ---------\n"; // DBG
}

MainMenuState::~MainMenuState()
{
    delete m_background;
    delete m_play;
    delete m_exit;
    std::cout << "--------- Main Menu State Destroyed! ---------\n"; // DBG
}

void MainMenuState::init()
{
    m_background->setSize({ WINDOW_WIDTH, WINDOW_HEIGHT });
    // m_background->setFillColor(sf::Color::Blue);
    m_background->setTexture(&TextureManager::get_backg_texture()); // DBG

    m_play->getButtonObject().setFillColor(sf::Color::Green);
    m_exit->getButtonObject().setFillColor(sf::Color::Blue);    
}

GameState* MainMenuState::update()
{
    // std::cout << "Update" << std::endl; // DBG
    if (m_play->isClicked()) {
        std::cout << "=========== Play Clicked ===========\n";
        return new GamePlayState{ *this->m_window };
        delete this;
    }
    if (m_exit->isClicked()) {
        // quit the game
        std::cout << "=========== Exit Clicked ===========\n";
    }
    return nullptr;
}

void MainMenuState::render(sf::RenderWindow& window)
{
    // std::cout << "Render" << std::endl; // DBG
    window.draw(*m_background);
    m_play->render(window);
    m_exit->render(window);
}
