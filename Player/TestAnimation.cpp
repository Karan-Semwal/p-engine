// #include <SFML/Graphics.hpp>
// #include "Animator.h"
// #include "TextureManager.h"
// #include "Player.h"
// #include "PlayerController.h"
// #include <cmath>

// class Map 
// {
// public:
//     Map() {
//         rectangle.setSize(sf::Vector2f(64, 64));
//         rectangle.setTexture(&TextureManager::get_dirt_texture());
//     }
//     ~Map() {}

//     void loadMap(sf::RenderWindow& window) {
//         for (int i = 0; i < 16; i++) {
//             for (int j = 0; j < 9; j++) {
//                 char tileType = level1[i + j * 16];  // Calculate the correct index

//                 if (tileType == 'w') {
//                     rectangle.setTexture(&TextureManager::get_wall_texture());
//                 } else if (tileType == 'g') {
//                     //rectangle.setTexture(&TextureManager::get_grass_texture());
//                 } else if (tileType == '.') {
//                     rectangle.setTexture(&TextureManager::get_dirt_texture());
//                 }
                
//                 rectangle.setPosition(sf::Vector2f(64 * i, 64 * j));
//                 window.draw(rectangle);
//             }
//         }
//     }

//     bool checkObstacles(int x, int y) {
//         if (level1[x - 1] != '.')
//             return true;
//         if (level1[x + 1] != '.')
//             return true;
//         if (level1[y - 1] != '.')
//             return true;
//         if (level1[y - 1] != '.')
//             return true;
//         return false;
//     }

// private:
//     const std::string level1 = 
//             "wwwwwwwwwwwwwwww"
//             "................"
//             "................"
//             "................"
//             "................"
//             "................"
//             "................"
//             "................"
//             "................";

//     sf::RectangleShape rectangle;
// };

// // Test Animation
// int main()
// {
//     Map map;

//     const short TILE_SIZE = 64;
//     // 16 : 9 aspect ratio
//     sf::RenderWindow window(sf::VideoMode(TILE_SIZE * 16, TILE_SIZE * 9), "Sprite Animation");
//     window.setFramerateLimit(60);

//     // Player
//     Player player;
//     player.getObject().setPosition(400.f, 400.f);

//     while (window.isOpen())
//     {
//         if (window.hasFocus()) 
//         {
//             sf::Event event;
//             while (window.pollEvent(event))
//             {
//                 if (event.type == sf::Event::Closed)
//                     window.close();
//             }
//         }

//         // Update
//         float x = std::floor(player.getPosition().x / 9);
//         float y = std::floor(player.getPosition().y / 16);
//         //std::cout << x << " " << y << std::endl;

//         //if (!map.checkObstacles(x, y))
//             player.update();

//         // Render
//         window.clear(sf::Color(150, 150, 150, 255));
//         map.loadMap(window);
//         player.render(window);
//         window.display();
//     }
// }
