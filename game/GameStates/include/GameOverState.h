#pragma once
#include "GameState.h"

namespace sf
{
    struct RectangleShape;
}
struct Button;

class GameOverState : public GameState
{
public:
    GameOverState(sf::RenderWindow &window);
    ~GameOverState();

    GameState *update() override;
    void render(sf::RenderWindow &window) override;

private:
    void init();

private:
    sf::RectangleShape *m_background;
    sf::Texture *m_replayButtonTextureAddress;
    sf::Texture *m_exitButtonTextureAddress;
    Button *m_replay;
    Button *m_exit;
};