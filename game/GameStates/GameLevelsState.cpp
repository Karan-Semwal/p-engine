#include "GameLevelsState.h"
#include "GamePlayState.h"
#include "MainMenuState.h"

GameLevelsState::GameLevelsState(sf::RenderWindow &window)
    : GameState(window),
      m_totalNumOfLevels(TOTAL_NUMBER_OF_LEVELS)
{
    //m_levelButtons.reserve(m_totalNumOfLevels);
    m_background = new sf::RectangleShape{};
    sf::Texture texture; // DBG
    m_backButton = new Button{window, texture, 0 + BUTTON_W, WINDOW_HEIGHT - 50.f, BUTTON_W, BUTTON_H};
    init(window);
}

GameLevelsState::~GameLevelsState()
{
    delete m_background;
}

GameState* GameLevelsState::update()
{
    if (m_backButton->isClicked()) 
    {
        auto window = this->m_window;
        delete this;
        return new MainMenuState{*window};
    }

    int levelNum = levelButtonClick();
    if (levelNum == -1)
    {
        // no button was clicked
    }
    else {
        // Switch to Game Play State with clicked levelNum
        auto window = this->m_window;
        delete this;
        return new GamePlayState{*window, levelNum};
    }
    return nullptr;
}

void GameLevelsState::render(sf::RenderWindow& window)
{
    window.draw(*m_background);
    for (auto& button : m_levelButtons)
        button.render(window);

    m_backButton->render(window);
}

// NOTE: Keep Total Number of Levels to maximum 16 for
// the current resolution of window
void GameLevelsState::init(sf::RenderWindow& window)
{
    m_background->setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
    m_background->setTexture(&TextureManager::get_ocean_texture()); // DBG
    float rowStartPos = WINDOW_HEIGHT / (ROW_COUNT + 1);
    float colStartPos = WINDOW_WIDTH  / (COLUMN_COUNT + 1);
    sf::Texture texture; // DBG

    for (int i = 1; i <= m_totalNumOfLevels; i++)
    {
        LevelButton levelButton(window, 60.f, i, texture);
        // levelButton.getButtonObject().setFillColor(randomColor()); // DBG

        // position calculation to place buttons in a grid
        float x = colStartPos * (i % COLUMN_COUNT);
        if (x == 0)
            x = colStartPos * COLUMN_COUNT;
        float y = rowStartPos * (((i - 1) / ROW_COUNT) + 1);
        
        levelButton.setPos({ x, y });
        levelButton.setButtonText(TextureManager::get_boxButton_texture()); // DBG
        m_levelButtons.push_back(levelButton);
    }

    // back button
    m_backButton->getButtonObject().setFillColor(randomColor());
}

int GameLevelsState::levelButtonClick()
{
    for (size_t i = 0; i < m_levelButtons.size(); i++) {
        if (m_levelButtons.at(i).isClicked()) {
            return m_levelButtons.at(i).LevelNumber;
        }
    }
    return -1;
}