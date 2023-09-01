// #include "Tilemap.h"

// int main() {
//     sf::RenderWindow window(sf::VideoMode(16 *TILE_WITDTH, 9 * TILE_HEIGHT), "SFML Tilemap Rendering");
//     window.setFramerateLimit(60);

//     // Replace this with your map data

//     std::string mapData = Tilemap::loadLevel("/home/prime/Desktop/dev/cpp/sfml-testing/Map/Levels/level2.txt");
//     std::cout << mapData << std::endl;
//     Tilemap map(mapData);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         map.renderMap(window);
//         window.display();
//     }

//     return 0;
// }
