#include "uncontrollable-engine.hpp"

UncontrollableEngine::UncontrollableEngine(std::string id, Vec pos, 
        Vec thrustVec, double maxThrust, double duration) :
    BasicEngine(id, pos, thrustVec, maxThrust),
    duration(duration) {}

bool UncontrollableEngine::enable(double fuelConsumption) {
    (void)fuelConsumption;

    if(this->getState() != EngineState::BURNED) {
        this->setState(EngineState::RUNNING);
        return true;
    } else {
        return false;
    }
}
bool UncontrollableEngine::disable() {
    return false;
}

void UncontrollableEngine::update(double dt) {
    switch(this->getState()) {
        case EngineState::IDLE:
        case EngineState::BURNED:
            this->setThrust(0.0);
            break;

        case EngineState::RUNNING:
            this->duration -= dt;
            if(this->duration <= 0.0) {
                this->setState(EngineState::BURNED);
            }
            break;
    }
}
