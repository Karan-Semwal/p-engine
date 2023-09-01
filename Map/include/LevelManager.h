#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Tilemap.h"

class LevelManager
{
public:
    LevelManager()  {}
    ~LevelManager() {}

    std::string getLevelFilePath();
    std::string loadLevel(const std::string& levelFile);
    void switchLevel(Tilemap& map);

public:
    int currentLevel = 1;

private:
    std::string LEVEL_PATH_PREFIX = "../Map/Levels/";
    int MAX_LEVELS = 3;
};