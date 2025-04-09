#include <gtest/gtest.h>
#include "NeuralEngineLib/utils.h"

TEST(UtilsTest, LogMessage) {

    std::stringstream outBuffer;
    std::streambuf* oldOut = std::cout.rdbuf(outBuffer.rdbuf());

    log_message("Test logging");

    std::cout.rdbuf(oldOut);


#ifdef NEURAL_ENGINE_LOGGING
#if NEURAL_ENGINE_LOGGING == 1
    ASSERT_EQ(outBuffer.str(), "[NeuralEngine Log]: Test logging\n");
#else
    ASSERT_EQ(outBuffer.str(), "");
#endif
#else
    ASSERT_EQ(outBuffer.str(), "");
#endif
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
