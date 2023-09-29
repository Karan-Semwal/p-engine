#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Tilemap.h"

class Camera
{
public:
    Camera(Player& player, Tilemap& map, const sf::Vector2f& size);
    ~Camera();

    void clampX();
    void clampY();

    void update(Player& player);
    void render(sf::RenderWindow& window);

private:
    int m_minX;
    int m_maxX;
    int m_minY;
    int m_maxY;
    sf::Vector2f m_cameraSize;
    sf::View     m_camera;
};