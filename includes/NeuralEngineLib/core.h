#pragma once


#include <algorithm>


double compute_relu(double x) {
    return std::max(0.0, x);
}