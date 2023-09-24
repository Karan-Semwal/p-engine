#include "Physics.h"

Physics::Physics()
    : m_gravity(0.f, 0.f),
      m_world(std::make_unique<b2World>(m_gravity))
{
    timeStep = 1.0f / 30.f;
    velocityIterations = 6;
    positionIterations = 2;
}

Physics::~Physics()
{
}

void Physics::update()
{
    m_world->Step(timeStep, velocityIterations, positionIterations);
}
