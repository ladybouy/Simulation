#ifndef SIMULATION_H
#define SIMULATION_H
#include <memory>
#include <vector>
#include "PointMass.hpp"

inline std::vector<std::shared_ptr<PointMass>> SimulationObjects = std::vector<std::shared_ptr<PointMass>>();

void UpdateSimulation(double aTimeStep);

#endif
