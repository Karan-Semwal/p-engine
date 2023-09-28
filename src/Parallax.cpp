// #include <iostream>
// #include <SFML/Graphics.hpp>

// static constexpr float WIDTH  = 800.f;
// static constexpr float HEIGHT = 400.f;

// class Parallax
// {
// public:
//     Parallax()
//         : m_velocity(), m_object(nullptr), m_objects()
//     {
//     }

//     Parallax(sf::RectangleShape* object, sf::Vector2f velocity)
//         : m_velocity(velocity), m_object(object), m_objects()
//     {
//         setup();
//     }

//     ~Parallax() {}

//     void init(sf::RectangleShape* object, sf::Vector2f velocity)
//     {
//         m_object = object;
//         m_velocity = velocity;

//         setup();
//     }

//     void updateParallax()
//     {
//         if (m_object != nullptr) 
//         {
//             for (auto& obj : m_objects) {
//                 obj.move(m_velocity);
//                 if (obj.getPosition().x <= -1 * WIDTH / 2.f)
//                 {
//                     obj.setPosition(WIDTH + WIDTH / 2.f, obj.getPosition().y);
//                 }
//             }
//         } else {
//             std::cout << "The parallax object is nullptr\n";
//         }
//     }

//     void renderParallax(sf::RenderWindow& window) 
//     {
//         if (m_object != nullptr) 
//         {
//             for (auto& i : m_objects)
//                 window.draw(i);
//         }
//     }

// private:
//     void setup()
//     {
//         for (size_t i = 0; i < 3; i++) {
//             m_objects.push_back(*m_object);
//         }

//         // initial positions of background objects (clouds)
//         m_objects[0].setPosition(-1 * WIDTH / 2.f, HEIGHT / 2.f);
//         m_objects[1].setPosition(WIDTH / 2.f, HEIGHT / 2.f);
//         m_objects[2].setPosition(WIDTH + WIDTH / 2.f, HEIGHT / 2.f);
//     }

// private:
//     sf::RectangleShape* m_object;
//     std::vector<sf::RectangleShape> m_objects;
//     sf::Vector2f m_velocity;

// };

// struct Backg
// {
//     Backg()
//         : m_clouds   (sf::Vector2f(WIDTH, HEIGHT)),
//           m_mountains(sf::Vector2f(WIDTH, HEIGHT)),
//           m_city({ WIDTH, HEIGHT }),
//           m_cloudsText(),
//           m_mountainsText(),
//           m_cityText()
//     {
//         m_clouds.setOrigin(sf::Vector2f(WIDTH / 2.f, HEIGHT / 2.f));
//         m_cloudsText.loadFromFile("/home/prime/Desktop/dev/cpp/sfml-testing/res/cloud_scene.png");
//         m_clouds.setTexture(&m_cloudsText);

//         m_mountains.setOrigin(sf::Vector2f(WIDTH / 2.f, HEIGHT / 2.f));
//         m_mountainsText.loadFromFile("../res/mountains.png");
//         m_mountains.setTexture(&m_mountainsText);

//         m_city.setOrigin(sf::Vector2f(WIDTH / 2.f, HEIGHT / 2.f));
//         m_cityText.loadFromFile("../res/city.png");
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
//     sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Parallax", sf::Style::Default);
//     window.setFramerateLimit(60);

//     // clouds
//     Backg background;

//     // sun
//     sf::CircleShape sun(200.f);
//     sun.setPosition(sf::Vector2f(WIDTH / 2.f, HEIGHT / 2.f));
//     sun.setOrigin(sun.getRadius() / 2.f, sun.getRadius() / 2.f);
//     sun.setFillColor(sf::Color::Yellow);

//     // floor
//     sf::RectangleShape floor(sf::Vector2f(WIDTH, HEIGHT / 10));
//     floor.setPosition(sf::Vector2f(WIDTH / 2.f, HEIGHT - 10));
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