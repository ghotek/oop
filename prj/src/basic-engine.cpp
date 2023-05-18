#include <cassert>
#include "basic-engine.hpp"

std::string BasicEngine::getID() const {
    return id;
}
Vec BasicEngine::getPos() const {
    return pos;
}
Vec BasicEngine::getThrustNormal() const {
    return thrustVec;
}

double BasicEngine::getThrust() const {
    return thrust;
}
double BasicEngine::getMaxThrust() const {
    return maxThrust;
}
Vec BasicEngine::getThrustVec() const {
    return this->getThrustNormal() * this->getThrust();
}

EngineState BasicEngine::getState() const {
    return state;
}

void BasicEngine::setThrust(double thrust) {
    assert(thrust <= maxThrust);
    this->thrust = thrust;
}

void BasicEngine::setState(EngineState state) {
    this->state = state;
}

BasicEngine::BasicEngine(std::string id, Vec pos, Vec thrustVec, double maxThrust) :
    id(id), pos(pos), thrustVec(thrustVec), maxThrust(maxThrust),
    state(EngineState::IDLE) {}
