#include "Physics/Hitbox.h"

Hitbox::Hitbox(float x, float y, float w, float h, const sf::Color& color)
    : m_size({w, h}), m_position({x, y}), m_color{color}
{   
    init();
}

Hitbox::Hitbox(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color)
    : m_size{size}, m_position{pos}, m_color{color} 
{
    init();
}

Hitbox::~Hitbox()
{
}

void Hitbox::makeShapeTransparent() {
    if (transparent) {
        sf::Color colorOfShape{m_color};
        colorOfShape.a = 0;
        m_shape.setFillColor(colorOfShape);
        m_shape.setOutlineColor(sf::Color::Green);
        m_shape.setOutlineThickness(m_thickness);
    }
    else {
        m_shape.setFillColor(m_color);
        m_shape.setOutlineThickness(0.f);
    }
}

void Hitbox::init()
{
    m_thickness = 3.f;
    m_shape.setPosition(m_position);
    m_shape.setSize(m_size);
    sf::Vector2f center(m_position.x + (m_size.x / 2.f), m_position.y + (m_size.y / 2.f));
    m_shape.setOrigin(center); 
    makeShapeTransparent();
}

void Hitbox::update(const sf::Vector2f& pos)
{
    m_shape.setPosition(pos);
    m_shape.setSize(m_size);
    sf::Vector2f center(m_position.x + (m_size.x / 2.f), m_position.y + (m_size.y / 2.f));
    m_shape.setOrigin(center); 
    makeShapeTransparent();
}

void Hitbox::render(sf::RenderTarget& target)
{
    target.draw(m_shape);
}