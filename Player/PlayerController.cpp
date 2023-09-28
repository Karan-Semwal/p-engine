#include "PlayerController.h"
#include <cmath>

float lerpValue(float currentValue, float targetValue, float interpolationPoint)
{
    currentValue += interpolationPoint;
    if (currentValue > targetValue) {
        return targetValue;
    }
    return currentValue;
}

PlayerController::PlayerController()
    : m_velocity()
{
}

bool PlayerController::canMove(const sf::Vector2f& pos, Tilemap& map) {
    float playerX = pos.x;
    float playerY = pos.y;

    int pTileX = int(playerX / TILE_WIDTH_SIZE);
    int pTileY = int(playerY / TILE_HEIGHT_SIZE);

    char playerTile = map.getChatAtMap(pTileX, pTileY);
    return playerTile != '#';
}

void PlayerController::update(Player& player, Tilemap& map)
{
    sf::Vector2f pos = player.getPosition();
    sf::Vector2f vel = player.getVelocity();

    sf::Vector2f hitboxPos = player.hitbox.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::UP;
        if (canMove({player.hitbox.getTopLeft().x, player.hitbox.getTopLeft().y - vel.y} , map)) {
            if (canMove({player.hitbox.getTopRight().x, player.hitbox.getTopRight().y - vel.y} , map))
                player.setPosition({pos.x, pos.y - vel.y});
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::LEFT;
        if (canMove({player.hitbox.getTopLeft().x - vel.x, player.hitbox.getTopLeft().y} , map)) {
            if (canMove({player.hitbox.getBottomLeft().x - vel.x, player.hitbox.getBottomLeft().y} , map))
                player.setPosition({pos.x - vel.x, pos.y});
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::DOWN;
        if (canMove({player.hitbox.getBottomLeft().x, player.hitbox.getBottomLeft().y + vel.y} , map)) {
            if (canMove({player.hitbox.getBottomRight().x, player.hitbox.getBottomRight().y + vel.y} , map))
                player.setPosition({pos.x, pos.y + vel.y});
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::RIGHT;
        if (canMove({player.hitbox.getTopRight().x + vel.x, player.hitbox.getTopRight().y} , map)) {
            if (canMove({player.hitbox.getBottomRight().x + vel.x, player.hitbox.getBottomRight().y} , map))
                player.setPosition({pos.x + vel.x, pos.y});
        }
    }
    else
    {
        player.pstate = PlayerState::IDLE;            
    }

    // pos = pos + m_currentVelocity;
    // player.setPosition(pos);
    
    // TODO: reset the current velocity to zero when key is released
}


// void PlayerController::update(Player& player, CollisionSide& collSide)
// {
//     sf::Vector2f pos = player.getPosition();
//     sf::Vector2f vel{0.f, 0.f};

//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//     {
//         player.pstate = PlayerState::MOVE;
//         player.pfacingDirection = PlayerFacingDirection::UP;
//         if (!collSide.TOP) {
//             m_currentVelocity.y -= lerpValue(m_currentVelocity.y, player.getVelocity().y, this->m_velocityLerpValue);
//         }
//     }
//     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//     {
//         player.pstate = PlayerState::MOVE;
//         player.pfacingDirection = PlayerFacingDirection::LEFT;
//         if (!collSide.LEFT) {
//             m_currentVelocity.x -= lerpValue(m_currentVelocity.x, player.getVelocity().x, this->m_velocityLerpValue);
//         }
//     }
//     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//     {
//         player.pstate = PlayerState::MOVE;
//         player.pfacingDirection = PlayerFacingDirection::DOWN;
//         if (!collSide.BOTTTOM) {
//             m_currentVelocity.y = lerpValue(m_currentVelocity.y, player.getVelocity().y, this->m_velocityLerpValue);
//         }
//     }
//     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//     {
//         player.pstate = PlayerState::MOVE;
//         player.pfacingDirection = PlayerFacingDirection::RIGHT;
//         if (!collSide.RIGHT) {
//             m_currentVelocity.x = lerpValue(m_currentVelocity.x, player.getVelocity().x, this->m_velocityLerpValue);
//         }
//     }
//     else
//     {
//         player.pstate = PlayerState::IDLE;            
//     }

//     pos = pos + m_currentVelocity;
//     player.setPosition(pos);
    
//     // TODO: reset the current velocity to zero when key is released
// }
