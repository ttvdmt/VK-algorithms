#include "gtest/gtest.h"
#include "maxprofit.cpp"

TEST(maxprofit, empty)
{
	std::vector<int> nums;
	auto res = maxProfit(nums);
	ASSERT_EQ(res, 0);
}

TEST(maxprofit, 1)
{
	std::vector<int> nums = { 1 };
	auto res = maxProfit(nums);
	ASSERT_EQ(res, 0);
}

TEST(maxprofit, 2)
{
	std::vector<int> nums = { 8, 9, 3, 7, 4, 16, 12 };
	auto res = maxProfit(nums);
	ASSERT_EQ(res, 13);
}

TEST(maxprofitl, 3)
{
	std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	auto res = maxProfit(nums);
	ASSERT_EQ(res, 6);
}

TEST(maxprofit, 4)
{
	std::vector<int> nums = { 8, 7, 6, 5, 4, 3, 2 };
	auto res = maxProfit(nums);
	ASSERT_EQ(res, 0);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}