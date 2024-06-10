#include "gtest/gtest.h"
#include "findLIS.cpp"

TEST(findLIS, empty)
{
	std::vector<int> num;
	auto res = findLIS(num);
	ASSERT_EQ(res, 0);
}

TEST(findLIS, 1)
{
	std::vector<int> num = { 1 };
	auto res = findLIS(num);
	ASSERT_EQ(res, 1);
}

TEST(findLIS, 2)
{
	std::vector<int> num = { 3, 2, 8, 9, 5, 10 };
	auto res = findLIS(num);
	ASSERT_EQ(res, 3);
}

TEST(findLIS, 3)
{
	std::vector<int> num = { 1, 2, 7, 9, 0, 10 };
	auto res = findLIS(num);
	ASSERT_EQ(res, 4);
}

TEST(findLIS, 4)
{
	std::vector<int> num = { 8, 8, 8, 8 };
	auto res = findLIS(num);
	ASSERT_EQ(res, 1);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}