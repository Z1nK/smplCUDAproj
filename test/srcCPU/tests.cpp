#include "../../project/src/calculate.h"
#include "../../project/src/calculate.cpp"

#include <gtest/gtest.h>
#include <vector>
// #include "GPUtests.cu"

// class calculate
// {
// 	public:
// 		calculate(std::string str);
// 		std::vector<int> addCPU(std::vector<int> numb1, std::vector<int> numb2);
// 		std::vector<int> addGPU(std::vector<int> numb1, std::vector<int> numb2);
// };

TEST(addCPUtest, positive_firstBigger) {
    
    calculate calc("testing");
    std::vector<int> vec1{ 1,2,3,4,5,6,7 };
	std::vector<int> vec2{ 1,2,3,4,5,6 };

    std::vector<int> output = calc.addCPU(vec1, vec2);
    std::vector<int> expected{2, 4, 6, 8, 10, 12};

    ASSERT_EQ(output.size(), vec2.size()) << "Vectors output are of unequal length of smallest input vector";

    for (int i = 0; i < output.size(); ++i) {
        EXPECT_EQ(output[i], expected[i]) << "Expected and output differ at index " << i;
    }

    // vec1 = {1,2,3,4};
    // vec2 = {1,2,3,4,5,6,7};
    // expected = {2, 4, 6, 8};

    // output = calc.addCPU(vec1, vec2);

    // ASSERT_EQ(output.size(), vec1.size()) << "Vectors output are of unequal length of smallest input vector";

    // for (int i = 0; i < output.size(); ++i) {
    //     EXPECT_EQ(output[i], expected[i]) << "Expected and output differ at index " << i;
    // }


}

TEST(addCPUtest, positive_secondBigger) {
    
    calculate calc("testing");
    std::vector<int> vec1{ 1,2,3,4 };
	std::vector<int> vec2{ 1,2,3,4,5,6,7 };

    std::vector<int> output = calc.addCPU(vec1, vec2);
    std::vector<int> expected{2, 4, 6, 8};

    ASSERT_EQ(output.size(), vec1.size()) << "Vectors output are of unequal length of smallest input vector";

    for (int i = 0; i < output.size(); ++i) {
        EXPECT_EQ(output[i], expected[i]) << "Expected and output differ at index " << i;
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}