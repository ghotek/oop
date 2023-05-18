#pragma once

class FuelTank {
public:
    FuelTank(double maxAmount, double initialAmount);

    double getMaxAmount() const;
    double getCurAmount() const;

    double consumpt(double amount);

private:
    double maxAmount;
    double curAmount;
};
