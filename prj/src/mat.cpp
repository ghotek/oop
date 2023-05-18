#include "mat.hpp"

Mat::Mat() {
    for (int i = 0; i < 9; i++)
            data[i] = 0.0;
    data[0] = data[4] = data[8] = 1.0;
}

Mat operator* (Mat a, double b) {
    Mat c;
    for (int i = 0; i < 9; i++)
            c.data[i] = a.data[i] * b;
    return c;
}

Mat operator* (double a, Mat b) {
    return b * a;
}

Vec operator* (Mat a, Vec b) {
    return Vec(
        a.data[0 + 3 * 0] * b.x + a.data[0 + 3 * 1] * b.y + a.data[0 + 3 * 2] * b.z,
        a.data[1 + 3 * 0] * b.x + a.data[1 + 3 * 1] * b.y + a.data[1 + 3 * 2] * b.z,
        a.data[2 + 3 * 0] * b.x + a.data[2 + 3 * 1] * b.y + a.data[2 + 3 * 2] * b.z);
}
