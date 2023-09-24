#include "PlayerCollider.h"
#include <cmath>

PlayerCollider::PlayerCollider(Player& player)
    : Collider(player.getObject()),
      collisionSide()
{
}

void setPos(Player& player, float x, float y) {
    sf::Vector2f pos(x, y);
    player.getObject().setPosition(pos);
}

void PlayerCollider::onColliding()
{
    // player collision response
}

void PlayerCollider::update(Player& player, Tilemap& map)
{
    float playerX = player.getPosition().x;
    float playerY = player.getPosition().y;

    int pTileX = std::round(playerX / TILE_WIDTH_SIZE);
    int pTileY = std::round(playerY / TILE_HEIGHT_SIZE);

    char playerTile = map.getChatAtMap(pTileX, pTileY);
    char rightTile  = map.getChatAtMap(pTileX, pTileY); // DBG
    char leftTile   = map.getChatAtMap(pTileX - 1, pTileY);
    char topTile    = map.getChatAtMap(pTileX, pTileY);
    char bottomTile = map.getChatAtMap(pTileX, pTileY); // DBG

    this->collisionSide.resetCollisionSides();

    if (rightTile == '#') {
        this->collisionSide.RIGHT = true;
        // std::cout << "Colliding right\n"; // DBG
        setPos(player, playerX, playerY);
    }
    if (leftTile == '#') {
        this->collisionSide.LEFT = true;
        // std::cout << "Colliding left\n"; // DBG
        setPos(player, playerX, playerY);
    }
    if (topTile == '#') {
        this->collisionSide.TOP = true;
        // std::cout << "Colliding top\n"; // DBG
        setPos(player, playerX, playerY);
    }
    if (bottomTile == '#') {
        this->collisionSide.BOTTTOM = true;
        // std::cout << "Colliding bottom\n"; // DBG
        setPos(player, playerX, playerY);
    }

    // collision response
    onColliding();
}