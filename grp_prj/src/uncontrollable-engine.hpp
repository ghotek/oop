#pragma once

#include "basic-engine.hpp"
       
class UncontrollableEngine : public BasicEngine {
public:
    UncontrollableEngine(std::string id, Vec pos, Vec thrustVec, 
            double maxThrust, double duration);

    virtual bool enable(double fuelConsumption);
    virtual bool disable();

    virtual void update(double dt);
    
private:
    double duration;
};


