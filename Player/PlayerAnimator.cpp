#include "PlayerAnimator.h"

void PlayerAnimator::switchAnimation(Player& player)
{
    switch (player.pstate)
    {
        case PlayerState::IDLE:
            isIdle = true;
            break;
        case PlayerState::MOVE:
            isIdle = false;
            switch (player.pfacingDirection)
            {
                case PlayerFacingDirection::LEFT:
                    rows = 2;
                    isRight = false;
                    break;
                case PlayerFacingDirection::RIGHT:
                    isRight = true;
                    rows = 3;
                    break;
                case PlayerFacingDirection::UP:
                    isRight = false;
                    rows = 1;
                    break;
                case PlayerFacingDirection::DOWN:
                    isRight = false;
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
    int frameX{};
    int frameY{};
    if (!isIdle) 
    {
        if (m_timer.getElapsedTime() >= frameTime) {
            currentFrame++;
            m_timer.reset();

            if (currentFrame >= columns) { // DBG
                currentFrame = 0;
            }

            frameX = currentFrame % columns;
            frameY = rows;

            sprite.setTextureRect(sf::IntRect(
                frameX * sprite.getTextureRect().width,
                frameY * sprite.getTextureRect().height,
                sprite.getTextureRect().width,
                sprite.getTextureRect().height)
            );
        }
        m_timer.update();
    }
    else
    {
        if (isRight)
            frameX = 3; // only for the current spritesheet's Right idle state
        else
            frameX = 0;
        frameY = rows;
        sprite.setTextureRect(sf::IntRect(
            frameX * sprite.getTextureRect().width,
            frameY * sprite.getTextureRect().height,
            sprite.getTextureRect().width,
            sprite.getTextureRect().height)
        );
    }
}
