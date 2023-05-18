#pragma once

#include "vec.hpp"
#include "basic-engine.hpp"
#include "fuel-tank.hpp"

class ControllableEngine : public BasicEngine {
public:
    ControllableEngine(std::string id, Vec pos, Vec thrustVec, double maxThrust,
            double consumption, double maxConsumption, FuelTank& fuelTank);

    virtual bool enable(double fuelConsumption);
    virtual bool disable();

    virtual void update(double dt);

private:
    FuelTank& tank;

    double consumption;
    double maxConsumption;
};
 
