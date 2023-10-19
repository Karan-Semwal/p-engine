#pragma once
#include <vector>

#include "GameState.h"
#include "Button.h"

class MainMenuState : public GameState
{
public:
    MainMenuState();
    ~MainMenuState();

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::RectangleShape* m_background;
    std::vector<Button> m_buttons;
};