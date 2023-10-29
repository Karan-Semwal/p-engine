#pragma once
#include "GameState.h"

namespace sf {
    struct Texture;
}

class Button;
class GamePlayState;

class GamePauseState : public GameState
{
public:
    GamePauseState(sf::RenderWindow& window, GamePlayState* gamePlayState);
    ~GamePauseState();

    GameState* update() override;
    void render(sf::RenderWindow& window) override;

private:
    void init();

private:
    Button* m_resume;
    Button* m_quit;
    GamePlayState* m_gamePlayState;
    sf::Texture* m_resumeButtonTextureAddress;
    sf::Texture* m_quitButtonTextureAddress;
};