#pragma once
#include <SFML/Graphics.hpp>
#include "Tilemap.h"
#include "Player.h"
#include "Global.h"
#include "Camera.h"
#include "LevelManager.h"

class Game
{
public:
	Game();
	~Game();

	unsigned int getWindowWidth()  const { return window.getSize().x; }
	unsigned int getWindowHeight() const { return window.getSize().y; }

	void run();
	void resetGame();

private:
	void processEvents();
	void update();
	void render();
	void setup();

private:
	sf::RenderWindow window;
	bool isplaying;

	LevelManager m_levelManager;
	std::string  m_mapData;
	Tilemap		 m_tilemap;
	Player 		 m_player;
	Camera		 m_camera;
};