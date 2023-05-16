#include "Simulation.hpp"

void UpdateSimulation(double aTimeStep)
{
    for (int i = 0; i < SimulationObjects.size(); i++)
    {
        SimulationObjects[i]->Update(aTimeStep);
    }
}
