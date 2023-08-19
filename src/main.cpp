#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Animator.h"
#include <memory>
#include "Bar.h"

/*
sf::Vector2f operator-(sf::Vector2f& v1, sf::Vector2f& v2)
{
    sf::Vector2f resultMinus;
    resultMinus.x = v1.x - v2.x;
    resultMinus.y = v1.y - v2.y;
    return resultMinus;
}

sf::Vector2f operator/(sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x / n;
    resultDiv.y = v.y / n;
    return resultDiv;
}
*/

/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Animation");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("/home/prime/Desktop/sfml-testing/res/explosion.png");

    sf::RectangleShape player;
    player.setSize(sf::Vector2f(100.f, 100.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(100.f, 100.f);
    player.setOrigin(player.getTextureRect().width / 2.f, player.getTextureRect().height / 2.f);

    int alpha = 255;
    sf::Color c = player.getFillColor();
    c.a = alpha;

    // audio
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("/home/prime/Desktop/sfml-testing/sound/through_space.ogg"))
        std::cout << "Unable to load music\n";
    sf::Sound sound;
    sound.setBuffer(buffer);

    std::unique_ptr<sf::Time> offset = nullptr;

    // object
    sf::Texture textobj;
    textobj.loadFromFile("/home/prime/Desktop/sfml-testing/res/exitButton.png");
    
    sf::RectangleShape obj;
    obj.setSize(sf::Vector2f(200.f, 100.f));
    obj.setPosition(160.f, 170.f);
    obj.setTexture(&textobj);
    //obj.setFillColor(sf::Color::Red);

    //bar
    Bar bar;

    while (window.isOpen())
    {
        if (window.hasFocus()) 
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                // start and resume
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    if (offset == nullptr && sound.getStatus() != sf::Sound::Playing) {
                        sound.play();
                    } else if (sound.getStatus() != sf::Sound::Playing) {
                        sound.setPlayingOffset(*offset);
                        sound.play();
                        offset = nullptr;
                    }
                }
                // restart
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    sound.stop();
                    sound.play();
                    offset = nullptr;
                }
                // pause
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    if (sound.getStatus() == sound.Playing) {
                        offset = std::make_unique<sf::Time>();
                        *offset = sound.getPlayingOffset();
                        sound.pause();
                    }
                }
            }

            // update obj
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Color color = obj.getFillColor();
                color.r -= 10;
                color.g -= 10;
                color.b -= 10; 
                obj.setFillColor(color);
            }

            // update fade
            c.a = alpha;
            if (alpha <= 0) { alpha = 255; }
            player.setFillColor(c);
            alpha -= 2;

            // update bar
            bar.update();

            window.clear();
            window.draw(player);
            window.draw(obj);
            bar.render(window);
            window.display();
        }
    }
    return 0;
}
*/