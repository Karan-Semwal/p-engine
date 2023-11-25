#pragma once
#include "Animation/Animator.h"
#include "Player/PlayerState.h"
#include "Player/Player.h"

class PlayerAnimator : public Animator
{
public:
    PlayerAnimator(Player& player, sf::Texture& spriteSheet, int c, int r, float ft);
    ~PlayerAnimator() { }

    void switchAnimation(Player& player);
    void update(Player& player);

private:
    bool isIdle  {true};
    bool isRight {true}; // only for the current spritesheet's Right idle state
    
    int currentRow;
    int currentColumn;
};
