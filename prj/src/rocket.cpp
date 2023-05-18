#include "rocket.hpp"

Vec Rocket::getPos() const { 
   return this->pos;
}

Vec Rocket::getVel() const {
    return this->vel;
}

void Rocket::update(double dt) {
    pos = pos + vel * dt;
}

Rocket::Rocket(double mass, Mat inertia, Vec pos, Vec vel,
    std::vector<BasicEngine*> engines, std::vector<FuelTank*> tanks) :
    mass(mass), inertia(inertia), pos(pos), vel(vel), engines(engines),
    tanks(tanks) {}


