#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

const std::string TEXT_PATH_PLAYER = "../res/character.png";
const std::string TEXT_PATH_DIRT   = "../res/dirt.png";
const std::string TEXT_PATH_WALL   = "../res/wall.png";

class TextureManager
{
public:
    static sf::Texture& get_player_texture();
    static sf::Texture& get_dirt_texture();
    static sf::Texture& get_wall_texture();

private:
    static sf::Texture playerText;
    static sf::Texture dirtText;
    static sf::Texture wallText;
};
