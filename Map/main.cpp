#include "Tilemap.h"
#include "Player.h"
#include "LevelManager.h"
#include "Global.h"
#include "Util.h"
#include "Camera/include/Camera.h"

bool LOGGING = false;

bool checkRightCollision(Player& player, Tilemap& map) {
    sf::Vector2f tile;
    tile.x = player.getObject().getPosition().x / 64;
    tile.y = player.getObject().getPosition().y / 64;
    if (map[tile.x * tile.y + tile.y] == '#') {
        return true;
    }
    return false;
}

sf::Vector2i tile(0, 0);

int main()
{
    sf::RenderWindow window(sf::VideoMode(16 * TILE_WIDTH_SIZE, 9 * TILE_HEIGHT_SIZE), "SFML Tilemap Rendering");
    window.setFramerateLimit(60);

    // LM
    LevelManager levelm;

    // Map
    std::string mapData = levelm.loadLevel("../Map/Levels/level2.txt");
    Tilemap map(mapData, 13, 61);
    map.printmap(); // DBG

    // Player
    Player player;
    player.setVelocity(sf::Vector2f(10.f, 10.f));
    player.getObject().setPosition(928.f, 472.f);

    sf::Vector2f viewSize(16 * TILE_WIDTH_SIZE, 9 * TILE_HEIGHT_SIZE);
    Camera camera(player, map, viewSize);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                LOGGING = true;
        }

        // update player
        player.update();
        camera.update(player);

        tile.x = player.getObject().getPosition().x / 64;
        tile.y = player.getObject().getPosition().y / 64;
        
        // switch level
        if (player.getPosition().x < 0) {
            levelm.switchLevel(map);
            std::cout << "Entered level" << levelm.currentLevel << std::endl; // DBG
            player.setPosition(sf::Vector2f(200.f, 100.f)); // DBG
            map.printmap();
        }
        
        if (LOGGING) {
            std::cout << "Posi: " << player.getObject().getPosition();
            std::cout << "Tile: " << tile;
        }
        window.clear();
        map.renderMap(window);
        camera.render(window);
        player.render(window);
        window.display();


        LOGGING = false;
    }
    return 0;
}
