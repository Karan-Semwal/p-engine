#include "PlayerController.h"

void PlayerController::update(Player& player, CollisionSide& collSide)
{
    sf::Vector2f pos = player.getPosition();
    sf::Vector2f vel = player.getVelocity();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::UP;
        if (!collSide.TOP) {
            player.setPosition(sf::Vector2f(pos.x, pos.y - vel.y));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::LEFT;
        if (!collSide.LEFT) {
            player.setPosition(sf::Vector2f(pos.x - vel.x, pos.y));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::DOWN;
        if (!collSide.BOTTTOM) {
            player.setPosition(sf::Vector2f(pos.x, pos.y + vel.y));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.pstate = PlayerState::MOVE;
        player.pfacingDirection = PlayerFacingDirection::RIGHT;
        if (!collSide.RIGHT) {
            player.setPosition(sf::Vector2f(pos.x + vel.x, pos.y));
        }
    }
    else
    {
        player.pstate = PlayerState::IDLE;            
    }
}