#include "PlayerController.h"
#include <cmath>

PlayerController::PlayerController()
    : m_velocity(5.f, 5.f)
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

void PlayerController::update(Player& player, Tilemap& map, sf::Event& event)
{
    sf::Vector2f pos = player.getPosition();
    sf::Vector2f vel { m_currentVelocity };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_currentVelocity.y = lerpValue(m_currentVelocity.y, m_velocity.y, m_velocityLerpValue);
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::UP;
        if (canMove({player.hitbox.getTopLeft().x, player.hitbox.getTopLeft().y - vel.y} , map)) {
            if (canMove({player.hitbox.getTopRight().x, player.hitbox.getTopRight().y - vel.y} , map))
                player.setPosition({pos.x, pos.y - vel.y});
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_currentVelocity.x = lerpValue(m_currentVelocity.x, m_velocity.x, m_velocityLerpValue);
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::LEFT;
        if (canMove({player.hitbox.getTopLeft().x - vel.x, player.hitbox.getTopLeft().y} , map)) {
            if (canMove({player.hitbox.getBottomLeft().x - vel.x, player.hitbox.getBottomLeft().y} , map))
                player.setPosition({pos.x - vel.x, pos.y});
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        m_currentVelocity.y = lerpValue(m_currentVelocity.y, m_velocity.y, m_velocityLerpValue);
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::DOWN;
        if (canMove({player.hitbox.getBottomLeft().x, player.hitbox.getBottomLeft().y + vel.y} , map)) {
            if (canMove({player.hitbox.getBottomRight().x, player.hitbox.getBottomRight().y + vel.y} , map))
                player.setPosition({pos.x, pos.y + vel.y});
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_currentVelocity.x = lerpValue(m_currentVelocity.x, m_velocity.x, m_velocityLerpValue);
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::RIGHT;
        if (canMove({player.hitbox.getTopRight().x + vel.x, player.hitbox.getTopRight().y} , map)) {
            if (canMove({player.hitbox.getBottomRight().x + vel.x, player.hitbox.getBottomRight().y} , map))
                player.setPosition({pos.x + vel.x, pos.y});
        }
    }
    else {
        player.pstate = PlayerState::IDLE;            
    }
    
    // reset velocity after key released (reset velocity lerp)
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D || 
            event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S) 
        {
            m_currentVelocity = {0.f, 0.f};
        }
    }
}

void PlayerController::gravity(Player& player, Tilemap& map) {
    
    if (isInAir) {
        GRAVITY = lerpValue(GRAVITY, GRAVITY_LIMIT, GRAVITY_LERP_VALUE);
        sf::Vector2f pos = player.getPosition();
        if (canMove({player.hitbox.getBottomLeft().x, player.hitbox.getBottomLeft().y + GRAVITY} , map)) {
            if (canMove({player.hitbox.getBottomRight().x, player.hitbox.getBottomRight().y + GRAVITY} , map))
                player.setPosition({pos.x, pos.y + GRAVITY});
        }
    }
    else {
        GRAVITY = 0.f;
    }
}