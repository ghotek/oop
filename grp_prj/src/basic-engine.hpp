#pragma once

#include <string>
#include "vec.hpp"

enum class EngineState {
    IDLE = 0,
    RUNNING,
    BURNED
};

class BasicEngine {
public:
    std::string getID() const;
    Vec getPos() const;
    Vec getThrustNormal() const;

    double getThrust() const;
    double getMaxThrust() const;
    Vec getThrustVec() const;

    EngineState getState() const;

    virtual bool enable(double fuelConsumption) = 0;
    virtual bool disable() = 0;
    virtual void update(double dt) = 0;


protected:
    BasicEngine(std::string id, Vec pos, Vec thrustVec, double maxTrust);

    void setThrust(double thrust);
    void setState(EngineState state);

    std::string id;
    Vec pos;
    Vec thrustVec;

    double thrust;
    double maxThrust;

    EngineState state;
};


