
#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion
{
public:
    Quaternion();
    Quaternion(double w, double x, double y, double z);
    void Normalize();
private:
    double mW;
    double mX;
    double mY;
    double mZ;
};

#endif
