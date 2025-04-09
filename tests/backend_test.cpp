#include <gtest/gtest.h>
#include "NeuralEngineLib/backend.h"

TEST(BackendTest, GetBackendType) {
#ifdef NEURAL_ENGINE_USE_GPU
#if NEURAL_ENGINE_USE_GPU == 1
    ASSERT_EQ(get_backend_type(), "GPU");
#else
    ASSERT_EQ(get_backend_type(), "CPU");
#endif
#else
    ASSERT_EQ(get_backend_type(), "CPU");
#endif
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
