#include "Tilemap.h"
#include "Player.h"
#include "LevelManager.h"
#include "Global.h"
#include "Util.h"
#include "Camera.h"
#include "Physics.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(16 * TILE_WIDTH_SIZE, 9 * TILE_HEIGHT_SIZE), 
    "Testing");
    window.setFramerateLimit(60);
    // Physics
    Physics physics;

    // LM
    LevelManager levelm;

    // Map
    std::string mapData = levelm.loadLevel("../Map/Levels/level2.txt");
    Tilemap map(mapData, 13, 61);
    // map.printmap(); // DBG

    // Player
    Player player;
    player.setVelocity(sf::Vector2f(7.f, 7.f));
    player.getObject().setPosition(928.f, 472.f);

    sf::Vector2f viewSize(16 * TILE_WIDTH_SIZE, 9 * TILE_HEIGHT_SIZE);
    Camera camera(player, map, viewSize);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // update
        player.update(map);
        camera.update(player);

        // render
        window.clear();
        map.renderMap(window);
        camera.render(window);
        player.render(window);
        window.display();
    }
}
