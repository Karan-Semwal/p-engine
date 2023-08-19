#include "menu.h"

Menu::Menu(sf::RenderWindow& win)
  : window(win),
    playButton(win),
    exitButton(win),
    playButText(),
    exitButText()
{
    init();

    playButText.loadFromFile("../res/playButton.png");
    exitButText.loadFromFile("../res/exitButton.png");

    playButton.setButtonText(playButText);
    exitButton.setButtonText(exitButText);
}

Menu::~Menu()
{
}

void Menu::init()
{
    sf::Vector2f exitButPos(playButton.getButton().getPosition().x, playButton.getButton().getPosition().y + 100.f);
    exitButton.setButtonPos(exitButPos);
    exitButton.getButton().setFillColor(sf::Color::Cyan);
}

void Menu::update()
{
    if (playButton.isClicked()) {
        std::cout << "Play clicked!\n";
        isPlaying = true;
    }

    if (exitButton.isClicked()) {
        std::cout << "Exit clicked!\n";
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        isPlaying = false;
}

void Menu::render()
{
    playButton.render();
    exitButton.render();
}