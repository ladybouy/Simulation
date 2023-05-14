#include "Missile.hpp"


Missile::Missile(std::string aName, double aMass, double aReferenceArea, double aZeroLiftDragCoeff)
{
    mName = aName;
    mMass = aMass; 
    mReferenceArea = aReferenceArea;
    mZeroLiftDragCoeff = aZeroLiftDragCoeff; 
}
