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
                    currentRow = 2;
                    isRight = false;
                    break;
                case PlayerFacingDirection::RIGHT:
                    isRight = true;
                    currentRow = 3;
                    break;
                case PlayerFacingDirection::UP:
                    isRight = false;
                    currentRow = 1;
                    break;
                case PlayerFacingDirection::DOWN:
                    isRight = false;
                    currentRow = 0;
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

            if (currentFrame >= currentColumn) { // DBG
                currentFrame = 0;
            }

            frameX = currentFrame % currentColumn ;
            frameY = currentRow;

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
        frameY = currentRow;
        sprite.setTextureRect(sf::IntRect(
            frameX * sprite.getTextureRect().width,
            frameY * sprite.getTextureRect().height,
            sprite.getTextureRect().width,
            sprite.getTextureRect().height)
        );
    }
}
