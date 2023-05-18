#include <cmath>
#include "vec.hpp"

Vec::Vec(double x_, double y_, double z_) :
    x(x_), y(y_), z(z_) {}

double Vec::sqlen() {
    return x * x + y * y + z * z;
}
double Vec::len() {
    return sqrt(this->sqlen());
}

Vec operator+ (Vec a, Vec b) {
    return Vec(a.x + b.x, a.y + b.y, a.z + b.z);
}
Vec operator- (Vec a, Vec b) {
    return Vec(a.x - b.x, a.y - b.y, a.z - b.z);
}
Vec operator* (Vec a, double s) {
    return Vec(a.x * s, a.y * s, a.z * s);
}
Vec operator* (double s, Vec a) {
    return Vec(a.x * s, a.y * s, a.z * s);
}
Vec operator/ (Vec a, double s) {
    return Vec(a.x / s, a.y / s, a.z / s);
}
Vec operator+= (Vec a, Vec b) {
    return a + b;
}
