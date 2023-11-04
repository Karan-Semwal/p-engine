#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
    Button() = delete;
    Button(sf::RenderWindow &window, const sf::Texture &texture, float x, float y, float w, float h);
    Button(sf::RenderWindow &window, const sf::Texture &texture, const sf::Vector2f &position, const sf::Vector2f &size);
    ~Button() {}

    void update();
    void render(sf::RenderWindow &window);
    bool isClicked();
    void onClick();
    void onFocus();
    sf::RectangleShape &getButtonObject() { return m_button; }
    void setButtonText(const sf::Texture &texture);
    void setOnClick(std::function<void()> onClickFunction);
    void setOnFocus(std::function<void()> onFocusFunction);

public:
    float xPos, yPos;
    float width, height;
    bool isFocused;

private:
    void init();
    bool mouseIsOverButton();

    std::function<void()> onClickFunc;
    std::function<void()> onFocusFunc;

private:
    sf::RenderWindow *m_window;
    sf::RectangleShape m_button;
};