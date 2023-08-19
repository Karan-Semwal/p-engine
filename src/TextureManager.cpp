#include "TextureManager.h"

sf::Texture TextureManager::shipText;
sf::Texture TextureManager::bulletText;
sf::Texture TextureManager::playerText;

sf::Texture& TextureManager::get_ship_texture() 
{
    if (!shipText.loadFromFile(TEXT_PATH_SHIP)) {
        if (!shipText.loadFromFile(TEXT_RELATIVE_PATH_SHIP))
            std::cout << "Failed to load ship texture\n";
    }
    return shipText;
}

sf::Texture& TextureManager::get_bullet_texture()
{
    if (!bulletText.loadFromFile(TEXT_PATH_BULLET)) {
        if (!bulletText.loadFromFile(TEXT_RELATIVE_PATH_BULLET))
            std::cout << "Failed to load bullet texture\n";
    }
    return bulletText;
}

sf::Texture& TextureManager::get_player_texture()
{
    if (!playerText.loadFromFile(TEXT_PATH_PLAYER)) {
            std::cout << "Failed to load player texture\n";
    }
    return playerText;
}