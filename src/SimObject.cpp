#include "SimObject.hpp"
#include "PointMass.hpp"
#include <iostream>

void SimObject::Update(double aTimeStep) {}

std::shared_ptr<SimObject> MakeSimObjectFactory(SimObjectType aType)
{
    if (SimObjectType::POINTMASS == aType)
    {
        return std::make_shared<PointMass>();
    }
    else if (SimObjectType::RIGIDBODY == aType)
    {
        return std::make_shared<PointMass>(); // TODO Make RigidBody
    }
    return nullptr;
}
