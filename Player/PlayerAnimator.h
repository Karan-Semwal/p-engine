#pragma once
#include "Animator.h"
#include "PlayerState.h"
#include "Player.h"

class PlayerAnimator : public Animator
{
public:
    PlayerAnimator(sf::Sprite& object, sf::Texture& spriteSheet, int c, int r, float ft)
        : Animator(object, spriteSheet, c, r, ft)
    {
    }

    void switchAnimation(Player& player);
    void update() override;

private:
    bool isIdle = true;
    bool isRight = false; // only for the current spritesheet's Right idle state
};
