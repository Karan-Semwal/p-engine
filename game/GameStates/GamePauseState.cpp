#include "pengine.h"
#include "GamePauseState.h"
#include "GamePlayState.h"
#include "MainMenuState.h"

GamePauseState::GamePauseState(sf::RenderWindow& window, GamePlayState* gamePlayState)
    : GameState(window),
      m_gamePlayState { gamePlayState },
      m_resumeButtonTextureAddress{ nullptr },
      m_quitButtonTextureAddress  { nullptr }
{
    sf::Texture texture;
    // m_resume = new Button{ *this->m_window, texture, WINDOW_CENTER_X, WINDOW_CENTER_Y - 50, 100, 50 };
    // m_quit   = new Button{ *this->m_window, texture, WINDOW_CENTER_X, WINDOW_CENTER_Y + 50, 100, 50 };
    m_resume = new Button{ *this->m_window, *m_resumeButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y - 50, 100, 50 };
    m_quit   = new Button{ *this->m_window, *m_quitButtonTextureAddress  , WINDOW_CENTER_X, WINDOW_CENTER_Y + 50, 100, 50 };
    init();
    std::cout << "--------- Game Pause State Created! ---------\n"; // DBG
}

GamePauseState::~GamePauseState()
{
    delete m_resume;
    delete m_quit;
    std::cout << "--------- Game Pause State Destroyed! ---------\n"; // DBG
}

void GamePauseState::init()
{
    m_resume->getButtonObject().setFillColor(sf::Color::Green);
    m_quit->getButtonObject().setFillColor(sf::Color::Blue);
}

GameState* GamePauseState::update()
{
    if (m_resume->isClicked())
    {
        std::cout << "=========== Resume Clicked ===========\n";
        // resume the game from where it was paused
        return m_gamePlayState;
    }
    if (m_quit->isClicked())
    {
        std::cout << "=========== Quit Clicked ===========\n";
        auto tmpState = new MainMenuState{ *this->m_window };
        delete m_gamePlayState;
        return tmpState;
    }
    return nullptr;
}

void GamePauseState::render(sf::RenderWindow& window)
{
    std::cout << m_resume->getButtonObject().getPosition().x << std::endl;
    m_resume->render(window);
    m_quit->render(window);
}