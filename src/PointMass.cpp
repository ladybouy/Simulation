#include "PointMass.hpp"
#include "constants.hpp"
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

void PointMass::SetCd0(double aCd0)
{
    mCd0 = aCd0;
}

void PointMass::SetMass(double aMass)
{
    mMass = aMass;
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

Vec3D PointMass::CalcDrag(Vec3D aVelocity, double aDragCoefficient)
{
   return -1 * aDragCoefficient * std::pow(aVelocity.Magnitude(), 2) * aVelocity.Normal();
}

Vec3D PointMass::CalcForces(Vec3D aVelocity)
{
    // Reset forces:
    mForces.SetX(0);
    mForces.SetY(0);
    mForces.SetZ(0);

    // Gravity Force force
    mGravityForce.SetY(mMass*GRAVITY_ACCELERATION);

    // Drag force
    Vec3D dragForce = CalcDrag(mVelocity, mCd0);

    // Aggregate forces:
    mForces += mGravityForce;
    mForces += dragForce;
    return mForces;
}

void PointMass::UpdateBodyEuler(double aTimeStep)
{
    Vec3D acceleration;
    // Integrate thse equations of motion
    acceleration = CalcForces(mVelocity) / mMass;
    mVelocity +=  acceleration * aTimeStep;
    mPosition +=  mVelocity * aTimeStep;
}

void PointMass::UpdateRK4(double aTimeStep)
{
    Vec3D velocityK1 = Vec3D();
    Vec3D velocityK2 = Vec3D();
    Vec3D velocityK3 = Vec3D();
    Vec3D velocityK4 = Vec3D();

    Vec3D positionK1 = Vec3D();
    Vec3D positionK2 = Vec3D();
    Vec3D positionK3 = Vec3D();
    Vec3D positionK4 = Vec3D();

    velocityK1 = CalcForces(mVelocity) * aTimeStep / mMass;
    velocityK2 = CalcForces(mVelocity + velocityK1 / 2) * aTimeStep / mMass;
    velocityK3 = CalcForces(mVelocity + velocityK2 / 2) * aTimeStep / mMass;
    velocityK4 = CalcForces(mVelocity + velocityK3) * aTimeStep / mMass;

    positionK1 = mVelocity * aTimeStep;
    positionK2 = (mVelocity + velocityK1 / 2) * aTimeStep;
    positionK3 = (mVelocity + velocityK2 / 2) * aTimeStep;
    positionK4 = (mVelocity + velocityK3) * aTimeStep;

    mVelocity += (velocityK1 + 2 * (velocityK2 + velocityK2) + velocityK4) / 6;
    mPosition += (positionK1 + 2 * (positionK2 + positionK2) + positionK4) / 6;
}
