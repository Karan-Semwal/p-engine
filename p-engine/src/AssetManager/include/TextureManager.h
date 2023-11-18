#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Global.h"

const std::string TEXT_PATH_PLAYER = TEXTURE_DIR + "character.png";
const std::string TEXT_PATH_DIRT   = TEXTURE_DIR + "dirt.png";
const std::string TEXT_PATH_WALL   = TEXTURE_DIR + "wall.png";
const std::string TEXT_PATH_BACKG  = TEXTURE_DIR + "background-";
const std::string TEXT_PATH_PL  = TEXTURE_DIR + "play";

#define GET_TEXTURE_PATH(file) TEXTURE_DIR + file

class TextureManager
{
public:
    static sf::Texture& get_player_texture();
    static sf::Texture& get_dirt_texture();
    static sf::Texture& get_wall_texture();
    static sf::Texture& get_backg_texture(int n);
    static sf::Texture& get_playButton_texture();
    static sf::Texture& get_boxButton_texture();
    static sf::Texture& get_ocean_texture();

private:
    static sf::Texture playerText;
    static sf::Texture dirtText;
    static sf::Texture wallText;
    static sf::Texture backgText;
    static sf::Texture playButtonText;
    static sf::Texture boxButton;
    static sf::Texture oceanText;
};
