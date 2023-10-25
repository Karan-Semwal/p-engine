#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState : public GameState
{
public:
    MainMenuState(sf::RenderWindow& window);
    ~MainMenuState();

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    void init();

private:
    sf::RectangleShape* m_background;
    Button* m_play;
    Button* m_exit;

};