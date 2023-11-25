#include "pengine.h"
#include "GameStateManager.h"

int main()
{
    // initialize engine
    pengine::init();

    // Game Window
    sf::VideoMode videoMode{WINDOW_WIDTH, WINDOW_HEIGHT};
    sf::RenderWindow window{videoMode, "test-game", sf::Style::Close};
    window.setFramerateLimit(60);

    // GameStateManager Instance
    GameStateManager *gameStateManager = GameStateManager::getInstance(window);

    // Game loop
    while (window.isOpen())
    {
        if (window.hasFocus())
        {
            // poll events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            // update
            gameStateManager->update();
            // render
            window.clear();
            gameStateManager->render(window);
            window.display();
        }
    }
}
