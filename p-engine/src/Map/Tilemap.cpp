#include "Tilemap.h"
#include <cmath>

Tilemap::Tilemap(const std::string& mapData)
    : mapData(mapData)
{
    tileWidth  = TILE_WIDTH_SIZE;
    tileHeight = TILE_HEIGHT_SIZE;
    rows = 9;
    cols = 16;
    mapWidth  = tileWidth  * cols;
    mapHeight = tileHeight * rows;
}

Tilemap::Tilemap(const std::string& mapData, int r, int c) 
    : mapData(mapData) 
{
    tileWidth  = TILE_WIDTH_SIZE;
    tileHeight = TILE_HEIGHT_SIZE;
    rows = r;
    cols = c;
    mapWidth  = tileWidth  * cols;
    mapHeight = tileHeight * rows;
}

void Tilemap::render(sf::RenderWindow& window) 
{
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            char tileType = mapData[row * cols + col];

            if (tileType == '.') {
                mapSprite.setTexture(TextureManager::get_dirt_texture()); // Dirt tile
            } 
            else if (tileType == '#') {
                mapSprite.setTexture(TextureManager::get_wall_texture()); // Wall tile
            }

            mapSprite.setPosition(col * tileWidth, row * tileHeight);
            window.draw(mapSprite);
        }
    }
}

void Tilemap::printmap()
{
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            char ch = mapData[row * cols + col];
            std::cout << ch;
            if (col == cols - 1)
                std::cout << "\n";            
        }
    }
}

void Tilemap::switchMap(const std::string& levelString)
{
    this->mapData = levelString;
}

char Tilemap::getChatAtMap(int x, int y)
{
    char character = '!';
    int index = y * cols + x;
    if (index > 0 && index < this->mapData.size()) {
        character = this->mapData[index];
    }
    else {
        std::cout << "Invalid map index\n";
    }
    return character;
}

char Tilemap::getChatAtMap(const sf::Vector2f& pos)
{
    int x = std::round(pos.x);
    int y = std::round(pos.y);
    char character = '!';
    int index = y * cols + x;
    if (index > 0 && index < this->mapData.size()) {
        character = this->mapData[index];
    }
    else {
        std::cout << "Invalid map index\n";
    }
    return character;
}
