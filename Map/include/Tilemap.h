#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "TextureManager.h"
#include "Global.h"

class Tilemap
{
public:
    Tilemap(const std::string& mapData);
    Tilemap(const std::string& mapData, int r, int c) ;
    ~Tilemap() {}

    char operator[](int index) {
        return mapData[index];
    }
    void printmap();
    void switchMap(const std::string& levelString);
    void renderMap(sf::RenderWindow& window);
    void calcSpawnPos() {
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < cols; ++col) {
                char tileType = mapData[row * cols + col];
                if (tileType == '?') {
                    spawnPosition.x = row;
                    spawnPosition.y = col;
                }
            }
    }
    sf::Vector2f getMapSize() { return sf::Vector2f(mapWidth, mapHeight); }

public:
    sf::Vector2f spawnPosition;
    
private:
    std::string mapData;
    int tileWidth, tileHeight;
    int rows, cols;
    int mapWidth, mapHeight;
    sf::Texture tileset;
    sf::Sprite mapSprite;
};