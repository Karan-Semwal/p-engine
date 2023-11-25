#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils/Global.h"

class Parallax
{
public:
    Parallax();
    Parallax(sf::RectangleShape* object, sf::Vector2f velocity);
    ~Parallax();

    void init(sf::RectangleShape* object, sf::Vector2f velocity);
    void updateParallax();
    void renderParallax(sf::RenderWindow& window);

private:
    void setup();

private:
    sf::RectangleShape* m_object;
    std::vector<sf::RectangleShape> m_objects;
    sf::Vector2f m_velocity;

};
