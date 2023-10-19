#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "MathUtlities.hpp"
#include <memory>
#include <string>
#include <vector>
#include "Simulation.hpp"

int main(int argc, char **argv)
{
    // Constants
    double altitude = 0;      // m
    double mass     = 0.145;  // kg
    double diameter = 0.075;  // m
    double timeStep = 0.01;
    double density  = 1.225;  // kg/m^3

//    double dragConstant = (density * M_PI / 16 * std::pow(diameter,2));
    double dragConstant = 0;

    // Initial Conditions
    double velocity    = 30;  // m/s
    double gamma       = 45;  // deg
    double timeCounter = 0;
    std::cout << "#####################   Initializing Simulation   #####################" << '\n' << '\n';

    std::shared_ptr<SimObject> bullet = MakeSimObjectFactory(SimObjectType::POINTMASS);
    std::shared_ptr<PointMass> bulletPtr = std::dynamic_pointer_cast<PointMass>(bullet);
    bulletPtr->SetCd0(dragConstant);
    bulletPtr->SetMass(mass);
    bulletPtr->SetVelocity(velocity*std::cos(gamma*DEG_TO_RAD), velocity*std::sin(gamma*DEG_TO_RAD), 0); 
    bulletPtr->SetPosition(0, altitude, 0);
    bulletPtr->mIntegrationMethod = IntegrationMethod::RungeKutta4;
    SimulationObjects.push_back(bulletPtr); 
    std::ofstream trajectoryFile ("trajectory.csv");

    std::cout << '\n'<< "#####################   Starting Simulation   #####################" << '\n' << '\n';

    if (trajectoryFile.is_open())
    {
        trajectoryFile << "Time_sec" << "," << "Down_Range_m" << "," << "Cross_Range_m" << "," << "Altitude_m" << "\n";
    }
    
    auto startTime = std::chrono::high_resolution_clock::now(); 

    double apogeeAltitude = 0;
    while (bulletPtr->Position().Y() >= 0)
    {
        UpdateSimulation(timeStep);
        timeCounter += timeStep;
       
        if (bulletPtr->Position().Y() > apogeeAltitude)
        {
            apogeeAltitude = bulletPtr->Position().Y();
        }

        if (trajectoryFile.is_open())
        {
            trajectoryFile << timeCounter << "," << bulletPtr->Position().X() << "," << bulletPtr->Position().Z() << "," << bulletPtr->Position().Y() << "\n";
        }
    }

    std::cout << "Range: "          << bulletPtr->Position().X() << '\n';
    std::cout << "Apogee: "         << apogeeAltitude            << '\n';
    std::cout << "Time of Flight: " << timeCounter               << '\n';

    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = endTime - startTime;

    trajectoryFile.close();

    std::cout << "Execution Time: " <<  std::chrono::duration<double,std::milli>(duration).count() << " ms" << std::endl;

    std::cout << '\n'<< "#####################   End Simulation   #####################" << '\n';

    return 0;
}
