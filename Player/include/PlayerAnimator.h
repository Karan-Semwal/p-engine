#pragma once
#include "Animator.h"
#include "PlayerState.h"
#include "Player.h"

class PlayerAnimator : public Animator
{
public:
    PlayerAnimator(Player& player, sf::Texture& spriteSheet, int c, int r, float ft)
        : Animator(player.getObject(), spriteSheet, c, r, ft)
    {
        currentColumn = columns;
        if (player.pfacingDirection == PlayerFacingDirection::RIGHT) {
            isRight = true;
            currentRow = rows - 1;
        }
        if (player.pstate == PlayerState::IDLE) {
            isIdle = true;
        }
    }

    void switchAnimation(Player& player);
    void update() override;

private:
    bool isIdle  {true};
    bool isRight {true}; // only for the current spritesheet's Right idle state
    
    int currentRow;
    int currentColumn;
};
