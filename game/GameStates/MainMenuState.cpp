#include "MainMenuState.h"
#include <iostream>

MainMenuState::MainMenuState()
{

}

MainMenuState::~MainMenuState()
{
    delete m_background;
    delete m_play;
    delete m_quit;
}

void MainMenuState::init()
{

}

void MainMenuState::update()
{
    // std::cout << "Update" << std::endl; // DBG

}

void MainMenuState::render(sf::RenderWindow& window)
{
    // std::cout << "Render" << std::endl; // DBG

}
