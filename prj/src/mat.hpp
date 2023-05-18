#pragma once

#include "vec.hpp"

struct Mat {
    Mat();
    double data[9];
};

// TODO
Mat operator* (Mat a, Mat b);

Mat operator* (Mat a, double b);
Mat operator* (double a, Mat b);
Vec operator* (Mat a, Vec b);
