#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include "Simulation.hpp"

int main(int argc, char **argv)
{
    // Constants
    // Initial Conditions
    double altitude = 1000;
    double loftAngle = 30;
    double timeStep  = 0.05;
    double timeCounter = timeStep;

    std::cout << "#####################   Initializing Simulation   #####################" << '\n' << '\n';

    std::shared_ptr<SimObject> bullet = MakeSimObjectFactory(SimObjectType::POINTMASS);
    std::shared_ptr<PointMass> bulletPtr = std::dynamic_pointer_cast<PointMass>(bullet);
    bulletPtr->SetVelocity(200, 200, 200); 
    bulletPtr->SetPosition(0, altitude, 0);
    bulletPtr->mIntegrationMethod = IntegrationMethod::RungeKutta4;
    SimulationObjects.push_back(bulletPtr); 
    std::ofstream trajectoryFile ("trajectory.csv");

    if (trajectoryFile.is_open())
    {
        trajectoryFile << "Time_sec" << "," << "Down_Range_m" << "," << "Cross_Range_m" << "," << "Altitude_m" << "\n";
    }
    
    auto startTime = std::chrono::high_resolution_clock::now(); 

    while (bulletPtr->Position().Y() >= 0)
    {
        UpdateSimulation(timeStep);
        timeCounter += timeStep;

        if (trajectoryFile.is_open())
        {
            trajectoryFile << timeCounter << "," << bulletPtr->Position().X() << "," << bulletPtr->Position().Z() << "," << bulletPtr->Position().Y() << "\n";
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = endTime - startTime;

    trajectoryFile.close();

    std::cout << "Execution Time: " <<  std::chrono::duration<double,std::milli>(duration).count() << " ms" << std::endl;

    std::cout << '\n'<< "#####################   End Simulation   #####################" << '\n';

    return 0;
}
