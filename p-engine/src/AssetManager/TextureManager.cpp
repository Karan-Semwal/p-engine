#include "AssetManager/TextureManager.h"

void TextureManager::init()
{
    if (!playerText.loadFromFile(TEXT_PATH_PLAYER))
    {
        std::cout << "Failed to load player texture\n";
    }
    if (!dirtText.loadFromFile(TEXT_PATH_DIRT))
    {
        std::cout << "Failed to load dirt texture\n";
    }
    if (!wallText.loadFromFile(TEXT_PATH_WALL))
    {
        std::cout << "Failed to load wall texture\n";
    }
    if (!backgText.loadFromFile(TEXT_PATH_BACKG))
    {
        std::cout << "Failed to load background texture\n";
    }
    if (!playButtonText.loadFromFile(GET_TEXTURE_PATH("play.png")))
    {
        std::cout << "Failed to load play button texture\n";
    }
    if (!boxButton.loadFromFile(GET_TEXTURE_PATH("box-button.png")))
    {
        std::cout << "Failed to load box button texture\n";
    }
    if (!oceanText.loadFromFile(GET_TEXTURE_PATH("Ocean.png")))
    {
        std::cout << "Failed to load ocean texture\n";
    }
}

sf::Texture &TextureManager::get_player_texture()
{
    return playerText;
}

sf::Texture &TextureManager::get_dirt_texture()
{
    return dirtText;
}

sf::Texture &TextureManager::get_wall_texture()
{
    return wallText;
}

sf::Texture &TextureManager::get_backg_texture(int n)
{
    return backgText;
}

sf::Texture &TextureManager::get_playButton_texture()
{
    return playButtonText;
}

sf::Texture &TextureManager::get_boxButton_texture()
{
    return boxButton;
}

sf::Texture &TextureManager::get_ocean_texture()
{
    return oceanText;
}