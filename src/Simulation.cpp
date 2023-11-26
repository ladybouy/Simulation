#include "Simulation.hpp"

void UpdateSimulation(double aTimeStep)
{
    for (unsigned int i = 0; i < SimulationObjects.size(); i++)
    {
        SimulationObjects[i]->Update(aTimeStep);
    }
}
