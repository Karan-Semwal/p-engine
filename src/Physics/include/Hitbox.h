#pragma once
#include <SFML/Graphics.hpp>

class Hitbox
{
public:
    Hitbox() = delete;
    Hitbox(float x, float y, float w, float h, const sf::Color& color = sf::Color::Red);
    Hitbox(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color = sf::Color::Red);
    ~Hitbox();

    void init();
    void makeShapeTransparent();
    void setColor(const sf::Color& color) { m_color = color; }
    void setSize(const sf::Vector2f& size) { m_size = size; }
    void setPosition(const sf::Vector2f& pos) { m_position = pos; }
    void setThickness(float borderThicknessValue) { m_thickness = borderThicknessValue; }
    sf::Color getColor() const { return m_color; }
    sf::Vector2f getSize() const { return m_size; }
    sf::Vector2f getPosition() const { return m_position; }
    void update(const sf::Vector2f& pos);
    void render(sf::RenderTarget& target);

    sf::Vector2f getTopLeft()     const { return {m_shape.getPosition().x - m_size.x / 2.f, m_shape.getPosition().y - m_size.y / 2.f, }; }
    sf::Vector2f getBottomLeft()  const { return {m_shape.getPosition().x - m_size.x / 2.f, m_shape.getPosition().y + m_size.y / 2.f, }; }
    sf::Vector2f getTopRight()    const { return {m_shape.getPosition().x + m_size.x / 2.f, m_shape.getPosition().y - m_size.y / 2.f, }; }
    sf::Vector2f getBottomRight() const { return {m_shape.getPosition().x + m_size.x / 2.f, m_shape.getPosition().y + m_size.y / 2.f, }; }

public:
    bool transparent = true;

private:
    float m_thickness;
    sf::Vector2f       m_size;
    sf::Vector2f       m_position;
    sf::Color          m_color;
    sf::RectangleShape m_shape;
};
