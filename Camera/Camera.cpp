#include "Camera.h"

Camera::Camera(Player& player, Tilemap& map, sf::Vector2f& size)
    : m_maxX(map.getMapSize().x), m_minX(0),
      m_maxY(map.getMapSize().y), m_minY(0) 
{
    m_camera.setSize(size);
}

Camera::~Camera()
{
}

void Camera::clampX() {
    sf::Vector2f size(m_camera.getSize());
    sf::Vector2f center(m_camera.getCenter());
    // clamp camera along x axis
    if (center.x - size.x / 2 < m_minX) {
        m_camera.setCenter(m_minX + size.x / 2, center.y);
    }
    if (center.x + size.x / 2 > m_maxX) {
        m_camera.setCenter(m_maxX - size.x / 2, center.y);
    }
}

void Camera::clampY() {
    sf::Vector2f size(m_camera.getSize());
    sf::Vector2f center(m_camera.getCenter());
    // clamp camera along y axis
    if (center.y - size.y / 2 < m_minY) {
        m_camera.setCenter(center.x, m_minY + size.y / 2);
    }
    if (center.y + size.y / 2 > m_maxY) {
        m_camera.setCenter(center.x, m_maxY - size.y / 2);
    }
}

void Camera::update(Player& player)
{
    sf::Vector2f pos(player.getPosition().x, player.getPosition().y);
    m_camera.setCenter(pos);
    clampX();
    clampY();
}

void Camera::render(sf::RenderWindow& window) 
{
    window.setView(this->m_camera);
}
