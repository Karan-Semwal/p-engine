#include "Ui/Bar.h"

Bar::Bar(float amount, float mx, float my)
    : max_x(mx), max_y(my),
      m_size(max_x, max_y),
      m_amount(amount)
{
    init();
}

void Bar::init()
{
    m_bar.setSize(m_size);
    m_bar.setPosition(20.f, 20.f);
    m_bar.setFillColor(sf::Color::Red);
}

void Bar::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->decrease();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        this->increase();
    }
    m_bar.setSize(m_size);
}

void Bar::increase()
{
    if (m_size.x < max_x)
        m_size.x += m_amount;
}

void Bar::decrease()
{
    if (m_size.x > 0.0f)
        m_size.x -= m_amount;
}

void Bar::render(sf::RenderWindow& window)
{
    window.draw(m_bar);
}