cmake_minimum_required(VERSION 3.26.3)
project(simulation VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES
    src/main.cpp
    src/Vec3D.cpp
    src/PointMass.cpp
    src/Simulation.cpp
    src/SimObject.cpp
)
add_executable(simulation ${SRC_FILES})
