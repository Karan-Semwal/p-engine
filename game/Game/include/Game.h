#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "pengine.h"

class Game
{
public:
	Game();
	~Game();

	void init();
	void resetGame();
	void update();
	void render(sf::RenderWindow& window);

private:
	sf::Event m_event;
	bool isplaying;

	LevelManager m_levelManager;
	std::string  m_mapData;
	Tilemap		 m_tilemap;
	Player 		 m_player;
	Camera		 m_camera;
};