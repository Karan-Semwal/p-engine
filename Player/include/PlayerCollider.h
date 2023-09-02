#pragma once
#include "Collider.h"
#include "CollisionSide.h"
#include "PlayerState.h"
#include "Player.h"

class PlayerCollider : public Collider
{
public:
    PlayerCollider(Player& player);
    ~PlayerCollider() { }

    void update(Player& player, Tilemap& map);
    void onColliding() override;

public:
    CollisionSide collisionSide;
};
