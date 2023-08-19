#include "PlayerAnimator.h"

void PlayerAnimator::switchAnimation(Player& player)
{
    switch (player.pstate)
    {
        case PlayerState::IDLE:
            isIdle = true;
            break;
        case PlayerState::MOVE:
            switch (player.pfacingDirection)
            {
                case PlayerFacingDirection::LEFT:
                    rows = 2;
                    break;
                case PlayerFacingDirection::RIGHT:
                    rows = 3;
                    break;
                case PlayerFacingDirection::UP:
                    rows = 1;
                    break;
                case PlayerFacingDirection::DOWN:
                    rows = 0;
                    break;
                default:
                    break;
            }
            break;
        case PlayerState::JUMP:
            break;
        case PlayerState::CROUCH:
            break;
        default:
            break;
    }
}

void PlayerAnimator::update()
{
    if (!isIdle) 
    {
        if (m_timer.getElapsedTime() >= frameTime) {
            currentFrame++;
            m_timer.reset();

            if (currentFrame >= columns) { // DBG
                currentFrame = 0;
            }

            int frameX = currentFrame % columns;
            int frameY = currentFrame / columns;

            sprite.setTextureRect(sf::IntRect(
                frameX * sprite.getTextureRect().width,
                frameY * sprite.getTextureRect().height,
                sprite.getTextureRect().width,
                sprite.getTextureRect().height)
            );
        }
        m_timer.update();
    }
}