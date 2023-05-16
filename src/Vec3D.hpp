#ifndef VEC3D_H
#define VEC3D_H

#include <iostream>

class Vec3D
{
public:
    Vec3D();
    Vec3D(double aX, double aY, double aZ);
    double X() const;
    double Y() const;
    double Z() const;
    void SetX(double aX);
    void SetY(double aY);
    void SetZ(double aZ);
    double Magnitude();
    void Normalize();
    void Reverse();
    Vec3D operator+=(const Vec3D &other);
    Vec3D operator-=(const Vec3D &other);
    Vec3D operator*=(double scalar);
    Vec3D operator/=(double scalar);
private:
    double mX;
    double mY;
    double mZ;
};
Vec3D operator+(const Vec3D& aVector1, const Vec3D aVector2);

Vec3D operator-(const Vec3D& aVector1, const Vec3D aVector2);

Vec3D operator*(const Vec3D& aVector, const double aScalar);

double operator*(const Vec3D& aVector1, const Vec3D aVector2);

Vec3D operator/(Vec3D& aVector, const double aScalar);

Vec3D operator^(Vec3D& aVector1, Vec3D& aVector2);


std::ostream& operator<<(std::ostream& os, const Vec3D& aVector);
#endif
