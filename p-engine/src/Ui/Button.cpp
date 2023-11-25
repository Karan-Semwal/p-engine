#include "Ui/Button.h"
#include <iostream>

Button::Button(sf::RenderWindow &window, const sf::Texture &texture, float x, float y, float w, float h)
    : m_window(&window), m_button{}, xPos{x}, yPos{y}, width{w}, height{h}
{
    init();
}

Button::Button(sf::RenderWindow &window, const sf::Texture &texture, const sf::Vector2f &position, const sf::Vector2f &size)
    : Button(window, texture, position.x, position.y, size.x, size.y)
{
}

bool Button::isClicked()
{
    if (mouseIsOverButton())
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            return true;

    return false;
}

void Button::onClick()
{
    if (this->isClicked())
    {
        onClickFunc();
    }
}

void Button::onFocus()
{
    if (this->isFocused)
    {
        onFocusFunc();
    }
}

bool Button::mouseIsOverButton()
{
    int MousePositionX = sf::Mouse::getPosition(*m_window).x;
    int MousePositionY = sf::Mouse::getPosition(*m_window).y;
    return (m_button.getGlobalBounds().contains(MousePositionX, MousePositionY));
}

void Button::update()
{
    onFocus();
    onClick();
}

void Button::render(sf::RenderWindow &window)
{
    window.draw(m_button);
}

void Button::init()
{
    m_button.setPosition(xPos, yPos);
    m_button.setSize({width, height});
    m_button.setFillColor(sf::Color::Blue);

    sf::Vector2f centre = sf::Vector2f(m_button.getSize().x / 2.f, m_button.getSize().x / 2.f);
    m_button.setOrigin(centre);
}

void Button::setOnClick(std::function<void()> onClickFunction)
{
    onClickFunc = onClickFunction;
}

void Button::setOnFocus(std::function<void()> onFocusFunction)
{
    onFocusFunc = onFocusFunction;
}

void Button::setButtonText(const sf::Texture &texture)
{
    m_button.setTexture(&texture);
}
