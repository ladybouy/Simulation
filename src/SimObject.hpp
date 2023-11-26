#ifndef SIM_OBJECT_H
#define SIM_OBJECT_H

#include <string>
#include <memory>

class SimObject 
{
    public: 
        virtual ~SimObject() {}
        virtual void Update(double aTimeStep);
};

enum class SimObjectType {POINTMASS, RIGIDBODY};
std::shared_ptr<SimObject> MakeSimObjectFactory(SimObjectType aType);

#endif
