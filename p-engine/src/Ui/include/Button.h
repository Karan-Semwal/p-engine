#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(sf::RenderWindow& win);
    Button(sf::RenderWindow& win, const sf::Texture& texture);
    ~Button();

    bool isClicked();
    bool mouseIsOverButton();

    sf::RectangleShape& getButton() { return button; }
    
    void setButtonPos(const sf::Vector2f& pos);
    void setButtonText(const sf::Texture& texture);
    void setButtonSize(const sf::Vector2f& size);

    void render();

private:
    void init();

private:
    sf::RectangleShape button;
    sf::Texture buttonText;
    sf::RenderWindow& window;
};