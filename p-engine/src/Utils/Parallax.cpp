#include "Parallax.h"

Parallax::Parallax()
    : m_velocity(), m_object(nullptr), m_objects()
{
}

Parallax::Parallax(sf::RectangleShape* object, sf::Vector2f velocity)
    : m_velocity(velocity), m_object(object), m_objects()
{
    setup();
}

Parallax::~Parallax() {}

void Parallax::init(sf::RectangleShape* object, sf::Vector2f velocity)
{
    m_object = object;
    m_velocity = velocity;

    setup();
}

void Parallax::updateParallax()
{
    if (m_object != nullptr) 
    {
        for (auto& obj : m_objects) {
            obj.move(m_velocity);
            if (obj.getPosition().x <= -1 * WINDOW_WIDTH / 2.f)
            {
                obj.setPosition(WINDOW_WIDTH + WINDOW_WIDTH / 2.f, obj.getPosition().y);
            }
        }
    } else {
        std::cout << "The parallax object is nullptr\n";
    }
}

void Parallax::renderParallax(sf::RenderWindow& window) 
{
    if (m_object != nullptr) 
    {
        for (auto& i : m_objects)
            window.draw(i);
    }
}

void Parallax::setup()
{
    for (size_t i = 0; i < 3; i++) {
        m_objects.push_back(*m_object);
    }

    // initial positions of background objects (clouds)
    m_objects[0].setPosition(-1 * WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);
    m_objects[1].setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);
    m_objects[2].setPosition(WINDOW_WIDTH + WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);
}
