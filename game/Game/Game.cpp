#include "Game.h"
#include <string>

Game::Game(int levelNumber)
    : isplaying(true),
      m_levelManager(),
      m_mapData(m_levelManager.loadLevel("level" + std::to_string(levelNumber) + ".txt")),
      m_tilemap(m_mapData, m_levelManager.getLevelRows(), m_levelManager.getLevelColumns()),
      m_player(),
      m_camera(m_player, m_tilemap, {16 * TILE_WIDTH_SIZE, 9 * TILE_HEIGHT_SIZE})
{
    init();
}

Game::~Game()
{
}

// ------------------ Update ------------------ //

void Game::update()
{
    m_player.update(m_tilemap, m_event);
    m_camera.update(m_player);
}

// ------------------ Render ------------------ //

void Game::render(sf::RenderWindow &window)
{
    this->m_tilemap.render(window);
    this->m_camera.render(window);
    this->m_player.render(window);
}

void Game::resetGame()
{
    isplaying = false;
    init();
}

void Game::init()
{
    this->m_player.setVelocity(sf::Vector2f(7.f, 7.f));
    this->m_player.getObject().setPosition(928.f, 472.f);
}