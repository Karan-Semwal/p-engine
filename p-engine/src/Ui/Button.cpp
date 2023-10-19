#include "Button.h"

Button::Button(sf::RenderWindow& window, const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size)
    : m_window(&window)
{
    setButtonText(texture);
    //pressKey = sf::Keyboard::Left;
    m_button.setTexture(&texture);

    this->x = position.x;
    this->y = position.y;
    this->w = size.x;
    this->h = size.y;
}

Button::Button(sf::RenderWindow& window, const sf::Texture& texture, float x, float y, float w, float h)
    : m_window(&window)
{
    setUp();
    setButtonText(texture);
    //pressKey = sf::Keyboard::Left;
    m_button.setTexture(&texture);

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
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
    if (this->isClicked()) {
        onClickFunc();
    }
}

void Button::onFocus() {
    if (this->isFocused) {
        onFocusFunc();
    }
}

bool Button::mouseIsOverButton()
{
    return (m_button.getGlobalBounds().contains(
        sf::Mouse::getPosition(*m_window).x,
        sf::Mouse::getPosition(*m_window).y)
    );
}

void Button::update()
{
    onFocus();
    onClick();
}

void Button::render(sf::RenderWindow& window) 
{
    window.draw(m_button);
}

void Button::setUp()
{

    m_button = sf::RectangleShape();
    m_button.setPosition(x, y);
    m_button.setSize({ w, h });
    m_button.setFillColor(sf::Color::Blue);
    
    sf::Vector2f centre = sf::Vector2f(m_button.getSize().x / 2.f, m_button.getSize().x / 2.f);
    m_button.setOrigin(centre);
}

void Button::init(std::function<void()> onClickFunction, std::function<void()> onFocusFunction)
{
    onClickFunc = onClickFunction;
    onFocusFunc = onClickFunction;
}

void Button::setButtonText(const sf::Texture& texture) {
    m_button.setTexture(&texture);
}
