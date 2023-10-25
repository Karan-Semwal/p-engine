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
    void onClick();
    void onFocus();
    sf::RectangleShape& getButtonObject() { return m_button; }
    void setButtonText(const sf::Texture& texture);
    void update();
    void render(sf::RenderWindow& window);
    void init(std::function<void()> onClickFunction, std::function<void()> onFocusFunction);
    
public:
    float x, y;
    float w, h;
    bool isFocused;
    std::function<void()> onClickFunc;
    std::function<void()> onFocusFunc;
    //sf::Keyboard::Key pressKey;

private:
    void setUp();
    bool mouseIsOverButton();

private:
    sf::RenderWindow* m_window;
    sf::RectangleShape m_button;
};