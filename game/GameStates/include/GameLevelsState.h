#pragma once
#include "GameState.h"
#include "pengine.h"
#include "Levels/Levels.h"

namespace sf {
    struct RectangleShape;
}
class Button;

class GameLevelsState : public GameState
{
public:
    GameLevelsState(sf::RenderWindow &window);
    ~GameLevelsState();

    GameState* update() override;
    void render(sf::RenderWindow& window) override;
    int levelButtonClick();

private:
    void init(sf::RenderWindow& window);

private:
    int m_totalNumOfLevels;
    sf::RectangleShape *m_background;
    Button* m_backButton;
    std::vector<LevelButton> m_levelButtons;
};