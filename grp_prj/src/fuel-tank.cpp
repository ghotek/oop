#include "fuel-tank.hpp"

FuelTank::FuelTank(double maxAmount, double initialAmount) :
    maxAmount(maxAmount), curAmount(initialAmount) {}

double FuelTank::getMaxAmount() const {
    return maxAmount;
}
double FuelTank::getCurAmount() const {
    return curAmount;
}

double FuelTank::consumpt(double amount) {
    if(amount > curAmount) {
        double res = curAmount;
        curAmount = 0.0;
        return res;
    } else {
        curAmount -= amount;
        return amount;
    }
}
