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
    void render(sf::RenderWindow& window);
    void calcSpawnPos(); // DBG
    sf::Vector2f getMapSize() { return sf::Vector2f(mapWidth, mapHeight); }
    char getChatAtMap(int x, int y);
    char getChatAtMap(const sf::Vector2f& pos);

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