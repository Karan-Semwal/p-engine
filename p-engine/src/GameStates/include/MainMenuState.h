#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState : public GameState
{
    MainMenuState();
    ~MainMenuState();

    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    
};