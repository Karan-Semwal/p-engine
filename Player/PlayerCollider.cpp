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

void checkRight()
{

}

void PlayerCollider::update(Player& player, Tilemap& map)
{
    float playerX = player.getPosition().x;
    float playerY = player.getPosition().y;

    int pTileX = std::round(playerX / TILE_WIDTH_SIZE);
    int pTileY = std::round(playerY / TILE_HEIGHT_SIZE);

    //
    // TOOD: Check collision with hitbox for all four corners
    //

    char playerTile = map.getChatAtMap(pTileX, pTileY);

    this->collisionSide.resetCollisionSides();

    // if (rightTile == '#') {
    //     this->collisionSide.RIGHT = true;
    //     setPos(player, playerX, playerY);
    // }
    // if (leftTile == '#') {
    //     this->collisionSide.LEFT = true;
    //     setPos(player, playerX, playerY);
    // }
    // if (topTile == '#') {
    //     this->collisionSide.TOP = true;
    //     setPos(player, playerX, playerY);
    // }
    // if (bottomTile == '#') {
    //     this->collisionSide.BOTTTOM = true;
    //     setPos(player, playerX, playerY);
    // }

    // collision response
    onColliding();
}

