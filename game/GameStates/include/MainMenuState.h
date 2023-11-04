#pragma once
#include "GameState.h"

class Button;
namespace sf
{
    struct Texture;
    struct RectangleShape;
}

class MainMenuState : public GameState
{
public:
    MainMenuState(sf::RenderWindow &window);
    ~MainMenuState();

    GameState *update() override;
    void render(sf::RenderWindow &window) override;

private:
    void init();

private:
    sf::RectangleShape *m_background;
    Button *m_play;
    Button *m_exit;
    sf::Texture *m_playButtonTextureAddress;
    sf::Texture *m_exitButtonTextureAddress;
};