#include "LevelManager.h"

std::string LevelManager::loadLevel(const std::string& levelFile)
{
    std::ifstream file(levelFile);
    if (!file.is_open()) {
        std::cerr << "Error opening level file: " << levelFile << std::endl;
        return "";
    }
    std::string content;
    std::string line;
    while (std::getline(file, line)) {
        content += line;
    }
    file.close();
    return content;
}

void LevelManager::switchLevel(Tilemap& map)
{
    currentLevel++;
    if (currentLevel > MAX_LEVELS)
        currentLevel = 1;
    std::string level = loadLevel(getLevelFilePath());
    map.switchMap(level);
}

std::string LevelManager::getLevelFilePath()
{
    std::string levelFilePath = LEVEL_PATH_PREFIX + "level" + std::to_string(currentLevel) + ".txt";
    return levelFilePath;
}