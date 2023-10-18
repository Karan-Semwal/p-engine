#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
    Button() = delete;
    Button(sf::RenderWindow& window, const sf::Texture& texture, float x, float y, float w, float h);
    Button(sf::RenderWindow& window, const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size);
    ~Button() {}

    bool isClicked();
    void onClick(std::function<void()> func);

    sf::RectangleShape& getButtonShape() { return m_button; }
    void setButtonText(const sf::Texture& texture);

    void render(sf::RenderWindow& window);
    void init();

public:
    float x, y;
    float w, h;
    bool isSelected;
    //sf::Keyboard::Key pressKey;

private:
    bool mouseIsOverButton();

private:
    sf::RenderWindow* m_window;
    sf::RectangleShape m_button;
};