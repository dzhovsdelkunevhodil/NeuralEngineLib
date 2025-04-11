#include "NeuralEngineLib/core.h"

#include <boost/math/special_functions/erf.hpp>

#include <cmath>

double compute_gelu(double x) {
    const double sqrt2 = std::sqrt(2.0);
    return x * 0.5 * (1.0 + boost::math::erf(x / sqrt2));
}