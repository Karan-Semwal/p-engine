#pragma once
#include "Player.h"
#include "Collider.h"
#include "PlayerState.h"

class PlayerCollider : public Collider
{
public:
    PlayerCollider(Player& player);
    ~PlayerCollider() { }

    void onColliding() override;
};
