#pragma once
#include <SFML/Graphics.hpp>
#include "menu.h"

class Game
{
public:
	Game();
	~Game();

	unsigned int getWindowWidth()  const { return window.getSize().x; }
	unsigned int getWindowHeight() const { return window.getSize().y; }

    void renderGameMenu();

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
    Menu mainMenu;
};