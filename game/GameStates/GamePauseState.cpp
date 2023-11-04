#include "pengine.h"
#include "GamePauseState.h"
#include "GamePlayState.h"
#include "MainMenuState.h"
#include <SFML/Graphics/RectangleShape.hpp>

GamePauseState::GamePauseState(sf::RenderWindow &window, GamePlayState *gamePlayState)
    : GameState(window),
      m_gamePlayState{gamePlayState},
      m_resumeButtonTextureAddress{nullptr},
      m_quitButtonTextureAddress{nullptr}
{
    sf::Texture texture;
    m_background = new sf::RectangleShape();
    m_resume = new Button{window, *m_resumeButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y - 50, 100, 50};
    m_quit = new Button{window, *m_quitButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y + 50, 100, 50};
    init();
}

GamePauseState::~GamePauseState()
{
    delete m_resume;
    delete m_quit;
}

GameState *GamePauseState::update()
{
    if (m_resume->isClicked())
    {
        // resume the game from where it was paused
        return m_gamePlayState;
    }
    if (m_quit->isClicked())
    {
        auto tmpState = new MainMenuState{*this->m_window};
        delete m_gamePlayState;
        return tmpState;
    }
    return nullptr;
}

void GamePauseState::render(sf::RenderWindow &window)
{
    window.draw(*m_background);
    m_resume->render(window);
    m_quit->render(window);
}

void GamePauseState::init()
{
    m_background->setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
    // Color
    m_background->setFillColor(randomColor());
    m_resume->getButtonObject().setFillColor(sf::Color::Yellow);
    m_quit->getButtonObject().setFillColor(sf::Color::Blue);
}