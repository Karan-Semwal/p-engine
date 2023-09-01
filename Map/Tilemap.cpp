#include "Tilemap.h"

Tilemap::Tilemap(const std::string& mapData)
    : mapData(mapData)
{
    tileWidth  = TILE_WIDTH_SIZE;
    tileHeight = TILE_HEIGHT_SIZE;
    rows = 9;
    cols = 16;
    calcSpawnPos();
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
    calcSpawnPos();
    mapWidth  = tileWidth  * cols;
    mapHeight = tileHeight * rows;
}

void Tilemap::renderMap(sf::RenderWindow& window) 
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