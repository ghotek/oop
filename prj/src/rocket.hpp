#pragma once

#include <vector>

#include "vec.hpp"
#include "mat.hpp"
#include "basic-engine.hpp"
#include "fuel-tank.hpp"

class Rocket {
public:
    Rocket(double mass, Mat inertia, Vec pos, Vec vel,
            std::vector<BasicEngine*> engines, std::vector<FuelTank*> tanks);

    Vec getPos() const;
    Vec getVel() const;

    void update(double dt);

private:
    double mass;
    Mat inertia;
    Vec pos;
    Vec vel;

    std::vector<BasicEngine*> engines;
    std::vector<FuelTank*> tanks;
};


