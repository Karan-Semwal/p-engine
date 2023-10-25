#include <iostream>
#include "MainMenuState.h"
#include "pengine.h"

MainMenuState::MainMenuState(sf::RenderWindow& window)
    : GameState(window)
{
    sf::Texture texture = TextureManager::get_dirt_texture();
    m_background = new sf::RectangleShape{};
    m_play = new Button{ *this->m_window, texture, WINDOW_CENTER_X, WINDOW_CENTER_Y - 50, 100, 50 };
    m_exit = new Button{ *this->m_window, texture, WINDOW_CENTER_X, WINDOW_CENTER_Y + 50, 100, 50 };
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
    m_background->setSize({ WINDOW_WIDTH, WINDOW_HEIGHT });
    m_background->setFillColor(sf::Color::Blue);

    m_play->getButtonObject().setFillColor(sf::Color::Green);
    m_exit->getButtonObject().setFillColor(sf::Color::White);    
}

void MainMenuState::update()
{
    // std::cout << "Update" << std::endl; // DBG

}

void MainMenuState::render(sf::RenderWindow& window)
{
    // std::cout << "Render" << std::endl; // DBG
    window.draw(*m_background);
    m_play->render(window);
    m_exit->render(window);
}
