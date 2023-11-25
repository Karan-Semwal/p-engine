#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Utils/Global.h"

const std::string TEXT_PATH_PLAYER = TEXTURE_DIR + "character.png";
const std::string TEXT_PATH_DIRT   = TEXTURE_DIR + "dirt.png";
const std::string TEXT_PATH_WALL   = TEXTURE_DIR + "wall.png";
const std::string TEXT_PATH_BACKG  = TEXTURE_DIR + "background-1.jpg";
const std::string TEXT_PATH_PL  = TEXTURE_DIR + "play";

#define GET_TEXTURE_PATH(file) TEXTURE_DIR + file

class TextureManager
{
public:
    void init();

    static TextureManager& getInstance()
    {
        static TextureManager textureManagerInstance;
        return textureManagerInstance;
    }

    sf::Texture& get_player_texture();
    sf::Texture& get_dirt_texture();
    sf::Texture& get_wall_texture();
    sf::Texture& get_backg_texture(int n);
    sf::Texture& get_playButton_texture();
    sf::Texture& get_boxButton_texture();
    sf::Texture& get_ocean_texture();

private:
    TextureManager() {}
    ~TextureManager() {}
    TextureManager(const TextureManager&) = delete;

    sf::Texture playerText;
    sf::Texture dirtText;
    sf::Texture wallText;
    sf::Texture backgText;
    sf::Texture playButtonText;
    sf::Texture boxButton;
    sf::Texture oceanText;
};
