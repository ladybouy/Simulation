#include <iostream>
#include <vector>
#include <cmath>
#include "Vec3D.hpp"

Vec3D::Vec3D()
    : mX(0), mY(0), mZ(0) {}

Vec3D::Vec3D(double aX, double aY, double aZ)
    : mX(aX), mY(aY), mZ(aZ) {}

double Vec3D::Y() const {return mY;}

double Vec3D::X() const {return mX;}

double Vec3D::Z() const {return mZ;}

void Vec3D::SetX(double aX) {mX = aX;}

void Vec3D::SetY(double aY) {mY = aY;}

void Vec3D::SetZ(double aZ) {mZ = aZ;}

double Vec3D::Magnitude()
{
    return std::sqrt(mX*mX + mY*mY + mZ*mZ);
}

void Vec3D::Normalize()
{
    double magnitude = std::sqrt(mX*mX + mY*mY + mZ*mZ);
    mX /= magnitude;
    mX /= magnitude;
    mX /= magnitude;
}

void Vec3D::Reverse()
{
    mX = -mX;
    mY = -mY;
    mZ = -mZ;
}

Vec3D Vec3D::operator+=(const Vec3D &other)
{
     mX += other.X();
     mY += other.Y();
     mZ += other.Z();
    return *this;
}

Vec3D Vec3D::operator-=(const Vec3D &other)
{
    mX -= other.X();
    mY -= other.Y();
    mZ -= other.Z();
    return *this;
}

Vec3D Vec3D::operator*=(double scalar)
{
    mX *= scalar;
    mY *= scalar;
    mZ *= scalar;
    return *this;
}

Vec3D Vec3D::operator/=(double scalar)
{
    mX /= scalar;
    mY /= scalar;
    mZ /= scalar;
    return *this;
}

Vec3D operator+(const Vec3D& aVector1, const Vec3D aVector2)
{
    return Vec3D(aVector1.X() + aVector2.X(), 
                 aVector1.Y() + aVector2.Y(),
                 aVector1.Z() + aVector2.Z());
}
Vec3D operator-(const Vec3D& aVector1, const Vec3D aVector2)
{
    return Vec3D(aVector1.X() - aVector2.X(), 
                 aVector1.Y() - aVector2.Y(),
                 aVector1.Z() - aVector2.Z());
}
double operator*(const Vec3D& aVector1, const Vec3D aVector2)
{
   return aVector1.X() * aVector2.X() + 
          aVector1.Y() * aVector2.Y() +
          aVector1.Z() * aVector2.Z();
}

Vec3D operator*(const Vec3D& aVector, const double aScalar) 
{
    return Vec3D(aVector.X() * aScalar,
                 aVector.Y() * aScalar,
                 aVector.Z() * aScalar);
}

Vec3D operator/(Vec3D& aVector, const double aScalar)
{
    return Vec3D(aVector.X() / aScalar,
                 aVector.Y() / aScalar,
                 aVector.Z() / aScalar);
}

Vec3D operator^(Vec3D& aVector1, Vec3D& aVector2)
{
    return Vec3D(aVector1.Y() * aVector2.Z() - aVector1.Z() * aVector2.Y(),
                 -aVector1.X() * aVector2.Z() + aVector1.Z() * aVector2.X(),
                 aVector1.X() * aVector2.Y() - aVector1.Y() * aVector2.X());

}

std::ostream& operator<<(std::ostream& os, const Vec3D& aVector)
{
    os << "{ " << aVector.X() << ", " << aVector.Y() << ", " << aVector.Z() << " }";
    return os;
}
