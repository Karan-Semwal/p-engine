#include "TextureManager.h"

sf::Texture TextureManager::playerText;
sf::Texture TextureManager::dirtText;
sf::Texture TextureManager::wallText;
sf::Texture TextureManager::backgText;
sf::Texture TextureManager::playButtonText;
sf::Texture TextureManager::boxButton;
sf::Texture TextureManager::oceanText;

sf::Texture& TextureManager::get_player_texture()
{
    if (!playerText.loadFromFile(TEXT_PATH_PLAYER)) {
            std::cout << "Failed to load player texture\n";
    }
    return playerText;
}

sf::Texture& TextureManager::get_dirt_texture()
{
    if (!dirtText.loadFromFile(TEXT_PATH_DIRT)) {
            std::cout << "Failed to load dirt texture\n";
    }
    return dirtText;
}

sf::Texture& TextureManager::get_wall_texture()
{
    if (!wallText.loadFromFile(TEXT_PATH_WALL)) {
            std::cout << "Failed to load wall texture\n";
    }
    return wallText;
}

sf::Texture& TextureManager::get_backg_texture(int n)
{
    if (!backgText.loadFromFile(TEXT_PATH_BACKG + std::to_string(n) + ".jpg")) {
        std::cout << "Failed to load background texture\n";
    }
    return backgText;
}

sf::Texture& TextureManager::get_playButton_texture()
{
    if (!playButtonText.loadFromFile(GET_TEXTURE_PATH("play.png"))) {
            std::cout << "Failed to load play button texture\n";
    }
    return playButtonText;
}

sf::Texture& TextureManager::get_boxButton_texture()
{
    if (!boxButton.loadFromFile(GET_TEXTURE_PATH("box-button.png"))) {
            std::cout << "Failed to load box button texture\n";
    }
    return boxButton;
}

sf::Texture& TextureManager::get_ocean_texture()
{
    if (!oceanText.loadFromFile(GET_TEXTURE_PATH("Ocean.png"))) {
            std::cout << "Failed to load ocean texture\n";
    }
    return oceanText;
}