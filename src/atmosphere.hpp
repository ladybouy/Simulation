#ifndef ATMOSPHERE_H
#define ATMOSPHERE_H

#include <vector>

class Atmosphere
{
    public:
        Atmosphere();
        ~Atmosphere();
        double Pressure(const double aAltitude_meters);
        double Density(const double aAltitude_meters);
        double SpeedOfSound(const double aAltitude_meters);
        double Temperature(const double aAltitude_meters);
    private:
        std::vector<double> mAltitude = std::vector<double>();
        std::vector<double> mSpeedOfSpound = std::vector<double>();
        std::vector<double> mTemperature = std::vector<double>();
        std::vector<double> mDensity = std::vector<double>();
};


#endif
