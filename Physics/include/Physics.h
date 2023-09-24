#pragma once
#include <memory>
#include <box2d/box2d.h>

class Physics
{
public:
    Physics();
    ~Physics();

    void update();

private:
    b2Vec2 m_gravity;
    float timeStep;
    int velocityIterations;
    int positionIterations;
    std::unique_ptr<b2World> m_world;
};
