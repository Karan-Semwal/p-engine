#pragma once

#define TEXT_RELATIVE_PATH_SHIP   "../res/ship.png"
#define TEXT_RELATIVE_PATH_BULLET "../res/bullet2.png"

#define TEXT_PATH_SHIP     "res/ship.png"
#define TEXT_PATH_BULLET   "res/bullet2.png"
#define TEXT_PATH_PLAYER   "/home/prime/Desktop/dev/cpp/sfml-testing/res/character.png"
#define TEXT_PATH_DIRT     "/home/prime/Desktop/dev/cpp/sfml-testing/res/4.png"
#define TEXT_PATH_WALL     "/home/prime/Desktop/dev/cpp/sfml-testing/res/wall.png"

#include <SFML/Graphics.hpp>
#include <iostream>

class TextureManager
{
public:
    static sf::Texture& get_ship_texture();
    static sf::Texture& get_bullet_texture();
    static sf::Texture& get_player_texture();
    static sf::Texture& get_dirt_texture();
    static sf::Texture& get_wall_texture();

private:
    static sf::Texture shipText;
    static sf::Texture bulletText;
    static sf::Texture playerText;
    static sf::Texture dirtText;
    static sf::Texture wallText;
};
