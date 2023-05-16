#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Vec3D.hpp"
#include "Simulation.hpp"
#include "PointMass.hpp"
#include "SimObject.hpp"

int main(int argc, char **argv)
{
    // Constants
    // Initial Conditions
    double altitude;
    double loftAngle=30;
    double timeStep = 0.05;
    double timeCounter = timeStep;

    std::shared_ptr<SimObject> bullet = MakeSimObjectFactory(SimObjectType::POINTMASS);
    std::shared_ptr<PointMass> bulletPtr = std::dynamic_pointer_cast<PointMass>(bullet);
    bulletPtr->SetVelocity(200, 200, 200); 
    bulletPtr->SetPosition(0, 1000, 0);
    SimulationObjects.push_back(bulletPtr); 
    std::ofstream trajectoryFile ("trajectory.csv");

    if (trajectoryFile.is_open())
    {
        trajectoryFile << "Time_sec" << "," << "Down_Range_m" << "," << "Cross_Range_m" << "," << "Altitude_m" << "\n";
    }
    
    while (bulletPtr->Position().Y() >= 0)
    {
        UpdateSimulation(timeStep);
        timeCounter += timeStep;

        if (trajectoryFile.is_open())
        {
            trajectoryFile << timeCounter << "," << bulletPtr->Position().X() << "," << bulletPtr->Position().Z() << "," << bulletPtr->Position().Y() << "\n";
        }
    }
    trajectoryFile.close();

    return 0;
}
