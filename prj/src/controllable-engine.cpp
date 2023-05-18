#include "controllable-engine.hpp"

ControllableEngine::ControllableEngine(std::string id, Vec pos, Vec thrustVec, 
        double maxThrust, double consumption, double maxConsumption, 
        FuelTank& fuelTank) :
    BasicEngine(id, pos, thrustVec, maxThrust),
    tank(fuelTank),
    consumption(consumption),
    maxConsumption(maxConsumption) {}

bool ControllableEngine::enable(double fuelConsumption) {
    if(this->getState() != EngineState::BURNED) {
        consumption = fuelConsumption;
        this->setState(EngineState::RUNNING);
        return true;
    } else {
        return false;
    }
}

bool ControllableEngine::disable() {
    if(this->getState() != EngineState::BURNED) {
        this->setState(EngineState::IDLE);
    }
    return true;
}

void ControllableEngine::update(double dt) {
    switch(this->getState()) {
    case EngineState::IDLE:
    case EngineState::BURNED:
        this->setThrust(0.0);
        break;

    case EngineState::RUNNING:
        double fuelWantToConsumpt = consumption * dt;
        double fuelConsumpted = tank.consumpt(fuelWantToConsumpt);

        this->setThrust(fuelConsumpted / maxConsumption * 
            this->getMaxThrust());

        if(fuelConsumpted == 0.0) {
            this->setState(EngineState::BURNED);
        }

        break;
    }
}

