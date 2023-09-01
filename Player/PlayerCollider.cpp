#include "PlayerCollider.h"

PlayerColliderPlayerCollider::(Player& player)
    : Collider(player.getObject())
{

}

void PlayerCollider::onColliding() override
{

}