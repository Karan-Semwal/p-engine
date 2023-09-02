#include "PlayerCollider.h"
#include <cmath>

PlayerCollider::PlayerCollider(Player& player)
    : Collider(player.getObject()),
      collisionSide()
{
}

void PlayerCollider::onColliding()
{
    // player collision response
}

void PlayerCollider::update(Player& player, Tilemap& map)
{
    // check for collision with all adjacent tiles
    int playerX = std::round(player.getPosition().x / TILE_WIDTH_SIZE);
    int playerY = std::round(player.getPosition().y / TILE_HEIGHT_SIZE);

    char playerTile = map.getChatAtMap(playerX, playerY); // DBG
    char rightTile  = map.getChatAtMap(playerX + 1, playerY);
    std::cout << rightTile << std::endl;
    char leftTile   = map.getChatAtMap(playerX - 1, playerY);
    char topTile    = map.getChatAtMap(playerX, playerY - 1);
    char bottomTile = map.getChatAtMap(playerX, playerY + 1);

    this->collisionSide.resetCollisionSides();

    if (rightTile == '#') {
        this->collisionSide.RIGHT = true;
        std::cout << "Colliding right\n"; // DBG
    }
    if (leftTile == '#') {
        this->collisionSide.LEFT = true;
        std::cout << "Colliding left\n"; // DBG
    }
    if (topTile == '#') {
        this->collisionSide.TOP = true;
        std::cout << "Colliding top\n"; // DBG
    }
    if (bottomTile == '#') {
        this->collisionSide.BOTTTOM = true;
        std::cout << "Colliding bottom\n"; // DBG
    }

    // collision response
    onColliding();
}