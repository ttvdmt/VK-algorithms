#include "gtest/gtest.h"
#include "coins.cpp"

TEST(coins, empty)
{
	std::vector<int> cns = { 0 };
	int amount = 0;
	auto res = coins(cns, amount);
	ASSERT_EQ(res, 0);
}

TEST(coins, 1)
{
	std::vector<int> cns = { 1, 2, 5 };
	int amount = 11;
	auto res = coins(cns, amount);
	ASSERT_EQ(res, 3);
}

TEST(coins, 2)
{
	std::vector<int> cns = { 2 };
	int amount = 3;
	auto res = coins(cns, amount);
	ASSERT_EQ(res, -1);
}

TEST(coins, 3)
{
	std::vector<int> cns = { 1, 2, 3, 4, 5 };
	int amount = 23;
	auto res = coins(cns, amount);
	ASSERT_EQ(res, 5);
}

TEST(coins, 4)
{
	std::vector<int> cns = { 1, 2 };
	int amount = 15;
	auto res = coins(cns, amount);
	ASSERT_EQ(res, 8);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}