#include <string>
class Missile
{
public:
    Missile(std::string aName, double aMass, double aReferenceArea, double aZeroLiftDragCoeff);
private:
    std::string mName;
    double mMass;
    double mReferenceArea;
    double mZeroLiftDragCoeff;
};
