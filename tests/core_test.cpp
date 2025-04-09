#include <gtest/gtest.h>
#include "NeuralEngineLib/core.h"

TEST(CoreTest, ComputeRelu) {

    ASSERT_DOUBLE_EQ(compute_relu(3.5), 3.5);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}