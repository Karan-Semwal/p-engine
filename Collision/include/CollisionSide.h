#pragma once

struct CollisionSide
{
    bool TOP     = false;
    bool BOTTTOM = false;
    bool LEFT    = false;
    bool RIGHT   = false;

    void resetCollisionSides() 
    {
        TOP     = false;
        BOTTTOM = false;
        LEFT    = false;
        RIGHT   = false;
    }
};