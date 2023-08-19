#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "TextureManager.h"
#include "Player.h"
#include "PlayerController.h"

// Test Animation
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Animation");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("/home/prime/Desktop/dev/cpp/sfml-testing/res/character.png");

    // Player
    Player player;
    player.getPlayer().setPosition(400.f, 400.f);

    // Animator a(texture, 4, 4, 6.f);
    // a.setScale(1.f, 1.f);
    // sf::Vector2f pos(300.f, 300.f);
    // a.setPosition(pos);

    while (window.isOpen())
    {
        if (window.hasFocus()) 
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }

        // Update
        //a.update();
        player.update();

        // Render
        window.clear(sf::Color(150, 150, 150, 255));
        //a.render(window);
        player.render(window);
        window.display();
    }
}
