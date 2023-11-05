#include "TextureManager.h"

sf::Texture TextureManager::playerText;
sf::Texture TextureManager::dirtText;
sf::Texture TextureManager::wallText;
sf::Texture TextureManager::backgText;

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