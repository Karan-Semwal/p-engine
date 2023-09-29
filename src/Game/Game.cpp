#include "Game.h"
#include <string>

Game::Game()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "p-engine", sf::Style::Default),
      isplaying(true),
      m_levelManager(),
      m_mapData(m_levelManager.loadLevel("level1.txt")),
      m_tilemap(m_mapData, m_levelManager.getLevelRows(), m_levelManager.getLevelColumns()),
      m_player(),
      m_camera(m_player, m_tilemap, {16 * TILE_WIDTH_SIZE, 9 * TILE_HEIGHT_SIZE})
{
    setup();
}

Game::~Game()
{
}

void Game::run()
{
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        if (window.hasFocus())
        {
            // poll events
            processEvents();

            if (isplaying)
            {
                update();
                render();
            }
        }
    }
}

void Game::resetGame()
{
    isplaying = false;
    setup();
}

void Game::setup()
{
    this->m_player.setVelocity(sf::Vector2f(7.f, 7.f));
    this->m_player.getObject().setPosition(928.f, 472.f);
}

void Game::processEvents()
{
    static sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}


// ------------------ Update ------------------ //

void Game::update()
{
    m_player.update(m_tilemap);
    m_camera.update(m_player);
}


// ------------------ Render ------------------ //

void Game::render()
{
    window.clear();

    this->m_tilemap.render(window);
    this->m_camera.render(window);
    this->m_player.render(window);

    window.display();
}
