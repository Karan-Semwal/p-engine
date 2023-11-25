#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Map/Tilemap.h"

class LevelManager
{
public:
    LevelManager()  {}
    ~LevelManager() {}

    std::string getLevelFilePath();
    std::string loadLevel(int levelNumber);
    void switchLevel(Tilemap& map);
    int getLevelColumns()  const { return m_levelWidth;  }
    int getLevelRows()     const { return m_levelHeight; }

public:
    int currentLevel = 1;

private:
    const int MAX_LEVELS = 3;
    int m_levelWidth  = 0;
    int m_levelHeight = 0;
};