#pragma once

struct Vec {
    Vec(double x_ = 0.0, double y_ = 0.0, double z_ = 0.0);

    double sqlen();
    double len();

    double x;
    double y;
    double z;
};


Vec operator+ (Vec a, Vec b);
Vec operator- (Vec a, Vec b);
Vec operator* (Vec a, double s);
Vec operator* (double s, Vec a);
Vec operator/ (Vec a, double s);
