#ifndef POINT_MASS_H
#define POINT_MASS_H

#include "Vec3D.hpp"
#include "SimObject.hpp"
#include "constants.hpp"

enum class IntegrationMethod {Euler, RungeKutta4};

class PointMass : public SimObject
{
    public:
        IntegrationMethod mIntegrationMethod = IntegrationMethod::Euler;
        PointMass();
        ~PointMass();
        PointMass(double aMass, double aCd0);
        double Mass();
        double Cd0();
        Vec3D Position();
        Vec3D Velocity();
        double Speed();
        Vec3D Acceleration();
        Vec3D Forces();
        void SetPosition(double aX, double aY, double aZ);
        void SetVelocity(double aX, double aY, double aZ);
        void SetAcceleration(double aX, double aY, double aZ);
        void CalcForces();
        void Update(double aTimeStep) override;
        void UpdateBodyEuler(double aTimeStep);
        void UpdateRK4(double aTimeStep);
    private:
        double mMass;
        double mCd0;
        Vec3D mPosition;
        Vec3D mVelocity;
        Vec3D mAcceleration;
        Vec3D mForces;
        Vec3D mGravityForce;
};

#endif
