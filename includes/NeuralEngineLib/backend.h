#pragma once

#include <string_view>

inline std::string_view get_backend_type() {
#ifdef NEURAL_ENGINE_USE_GPU
#if NEURAL_ENGINE_USE_GPU == 1
    return "GPU";
#else
    return "CPU";
#endif
#else
    return "CPU";
#endif
}