#pragma once

#include <iostream>
#include <string_view>

inline void log_message(const std::string_view msg) {
#ifdef NEURAL_ENGINE_LOGGING
#if NEURAL_ENGINE_LOGGING == 1
    std::cout << "[NeuralEngine Log]: " << msg << std::endl;
#endif
#endif
}