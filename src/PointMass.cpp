#include "PointMass.hpp"

PointMass::PointMass()
    : mMass(1), mCd0(0), mPosition(0,0,0), mVelocity(0,0,0), mAcceleration(0,0,0), mGravityForce(0,mMass*GRAVITY_ACCELERATION,0) {}

PointMass::PointMass(double aMass, double aCd0)
    : mMass(aMass), mCd0(aCd0), mGravityForce(0,mMass*GRAVITY_ACCELERATION,0) {}

PointMass::~PointMass() {}

void PointMass::Update(double aTimeStep)
{
    switch (mIntegrationMethod) 
    {
        case IntegrationMethod::Euler:
            UpdateBodyEuler(aTimeStep);
            break;
        case IntegrationMethod::RungeKutta4:
            UpdateRK4(aTimeStep);
            break;
        default:
            break; 
    }
}

double PointMass::Mass() { return mMass; }

double PointMass::Cd0() { return mCd0; }

Vec3D PointMass::Position() { return mPosition; }

Vec3D PointMass::Velocity() { return mVelocity; }

Vec3D PointMass::Acceleration() { return mAcceleration; }

double PointMass::Speed()
{
    return mVelocity.Magnitude();
}

Vec3D PointMass::Forces()
{
    return mForces;
}

void PointMass::SetPosition(double aX, double aY, double aZ)
{
    mPosition.SetX(aX); 
    mPosition.SetY(aY); 
    mPosition.SetZ(aZ); 
}

void PointMass::SetVelocity(double aX, double aY, double aZ)
{
    mVelocity.SetX(aX);
    mVelocity.SetY(aY);
    mVelocity.SetZ(aZ);
}

void PointMass::SetAcceleration(double aX, double aY, double aZ)
{
    mAcceleration.SetX(aX);
    mAcceleration.SetY(aY);
    mAcceleration.SetZ(aZ);
}

void PointMass::CalcForces()
{
    // Reset forces:
    mForces.SetX(0);
    mForces.SetY(0);
    mForces.SetZ(0);

    // Aggregate forces:
    mForces += mGravityForce;
}

void PointMass::UpdateBodyEuler(double timeStep)
{
    Vec3D acceleration;
    Vec3D deltaVelocity; 
    Vec3D deltaPosition; 

    // Integrate the equations of motion
    acceleration = mForces / mMass;

    deltaVelocity = acceleration * timeStep;
    mVelocity +=  deltaVelocity;
    
    deltaPosition = mVelocity * timeStep;
    mPosition += deltaPosition;
}

void PointMass::UpdateRK4(double timeStep)
{
    Vec3D force;
    Vec3D acceleration;
    Vec3D deltaVelocity; 
    Vec3D deltaPosition; 
    Vec3D k1, k2, k3, k4;
}
