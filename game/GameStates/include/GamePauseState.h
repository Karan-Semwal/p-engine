#pragma once
#include "GameState.h"

namespace sf
{
    struct Texture;
    struct RectangleShape;
}

class Button;
class GamePlayState;

class GamePauseState : public GameState
{
public:
    GamePauseState(sf::RenderWindow &window, GamePlayState *gamePlayState);
    ~GamePauseState();

    GameState *update() override;
    void render(sf::RenderWindow &window) override;

private:
    void init();

private:
    Button *m_resume;
    Button *m_quit;
    sf::RectangleShape* m_background;
    GamePlayState *m_gamePlayState;
    sf::Texture *m_resumeButtonTextureAddress;
    sf::Texture *m_quitButtonTextureAddress;
};