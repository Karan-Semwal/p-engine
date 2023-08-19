#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

class Menu
{
public:
    Menu(sf::RenderWindow& win);
    ~Menu();
    
    void update();
    void render();

public:
    bool isPlaying =  false;

private:
    void init();

private:
    Button playButton;
    Button exitButton;
    sf::RenderWindow& window;
    
    sf::Texture playButText;
    sf::Texture exitButText;
};
