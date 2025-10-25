#ifndef TEST_H
#define TEST_H

#include <cmath>
#include "../include/vector2d.h"

inline bool double_eq(double a, double b) {
    return std::abs(a - b) < Vector2D::eps;
}

#endif