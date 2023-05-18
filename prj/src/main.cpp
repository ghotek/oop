#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "rocket.hpp"

#define EPS 10e-7

int main() {
    Rocket rocket(1000, Mat(), Vec(400, 400, 0), Vec(25, 25, 0),
        std::vector<BasicEngine*>(), std::vector<FuelTank*>());

    double diff = 1;
    double cur_time = 0;

    while (fabs(cur_time - 10.0) > EPS) {
        std::cout << "( " << rocket.getPos().x << " "<< rocket.getPos().y 
            << " " << rocket.getPos().z << " )\n";
        
        rocket.update(diff);

        cur_time += diff;
    }

    return 0;
}
