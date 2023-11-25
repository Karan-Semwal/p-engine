// #include "Parallax.h"
// #include "Utils/Global.h"

// struct Backg
// {
//     Backg()
//         : m_clouds   (sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)),
//           m_mountains(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)),
//           m_city({ WINDOW_WIDTH, WINDOW_HEIGHT }),
//           m_cloudsText(),
//           m_mountainsText(),
//           m_cityText()
//     {
//         m_clouds.setOrigin(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f));
//         m_cloudsText.loadFromFile(TEXTURE_DIR + "cloud_scene.png");
//         m_clouds.setTexture(&m_cloudsText);

//         m_mountains.setOrigin(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f));
//         m_mountainsText.loadFromFile(TEXTURE_DIR + "mountains.png");
//         m_mountains.setTexture(&m_mountainsText);

//         m_city.setOrigin(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f));
//         m_cityText.loadFromFile(TEXTURE_DIR + "city.png");
//         m_city.setTexture(&m_cityText);

//         m_mountainsPrlx.init(&m_mountains, sf::Vector2f(-0.1f, 0.f));
//         m_cloudsPrlx.init   (&m_clouds   , sf::Vector2f(-0.7f , 0.f));
//         m_cityPrlx.init     (&m_city     , sf::Vector2f(-0.2f , 0.f));
//     }

//     ~Backg()
//     {
//     }

//     void update() {
//         m_mountainsPrlx.updateParallax();
//         m_cityPrlx.updateParallax();
//         m_cloudsPrlx.updateParallax();
//     }

//     void render(sf::RenderWindow& window) {
//         m_mountainsPrlx.renderParallax(window);
//         m_cityPrlx.renderParallax(window);
//         m_cloudsPrlx.renderParallax(window);
//     }

//     sf::RectangleShape m_clouds;
//     sf::Texture m_cloudsText;
//     Parallax    m_cloudsPrlx;

//     sf::RectangleShape m_mountains;
//     sf::Texture m_mountainsText;
//     Parallax    m_mountainsPrlx;

//     sf::RectangleShape m_city;
//     sf::Texture m_cityText;
//     Parallax    m_cityPrlx;
 
// };

// int main()
// {
//     // window
//     sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Parallax", sf::Style::Default);
//     window.setFramerateLimit(60);

//     // clouds
//     Backg background;

//     // sun
//     sf::CircleShape sun(200.f);
//     sun.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f));
//     sun.setOrigin(sun.getRadius() / 2.f, sun.getRadius() / 2.f);
//     sun.setFillColor(sf::Color::Yellow);

//     // floor
//     sf::RectangleShape floor(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT / 10));
//     floor.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT - 10));
//     floor.setOrigin(floor.getSize() / 2.f);
//     floor.setFillColor(sf::Color::Green);


//     while (window.isOpen())
//     {
//         sf::Event evnt;
//         while (window.pollEvent(evnt))
//         {
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
//             if (evnt.type == sf::Event::Closed) window.close();
//         }

//         // update
//         background.update();

//         // render
//         window.clear();
//         window.draw(sun);
//         background.render(window);
//         window.draw(floor);
//         window.display();
//     }
// }