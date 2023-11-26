#include "Quaternion.hpp"

Quaternion::Quaternion() : mW(0), mX(0), mY(0), mZ(0) {}
Quaternion::Quaternion(double aW, double aX, double aY, double aZ)
{
    mW = aW;
    mX = aX;
    mY = aY;
    mZ = aZ;
}

void Quaternion::Normalize()
{
}
