#include <cmath>
#include <iostream>
#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Pong", sf::Style::Close),
      isplaying(false), mainMenu(window) {
  setup();
}

Game::~Game() {}

void Game::renderGameMenu() {
  mainMenu.render();
  window.display();
}

void Game::run() {
  window.setFramerateLimit(60);
  while (window.isOpen()) {
    // poll events
    processEvents();

    if (isplaying) {
      update();
      render();
    }

    else
      renderGameMenu();
  }
}

void Game::resetGame() {
  isplaying = false;
  setup();
}

void Game::processEvents() {
  static sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window.close();
  }
}

void Game::update() {
  // TODO: UPDATE
}

void Game::render() {
  window.clear();

  // TODO: DRAW

  window.display();
}

void Game::setup() {
  
}