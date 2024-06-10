#include "gtest/gtest.h"
#include "pascal.cpp"

TEST(pascal, empty)
{
	int num = 0;
	auto res = pascal(num);
	std::vector<std::vector<int>> ans = { { 1 } };
	ASSERT_EQ(res, ans);
}

TEST(pascal, 1)
{
	int num = 1;
	auto res = pascal(num);
	std::vector<std::vector<int>> ans = { { 1 }, { 1, 1 } };
	ASSERT_EQ(res, ans);
}

TEST(pascal, 2)
{
	int num = 2;
	auto res = pascal(num);
	std::vector<std::vector<int>> ans = { { 1 }, { 1, 1 }, { 1, 2, 1 } };
	ASSERT_EQ(res, ans);
}

TEST(pascal, 3)
{
	int num = 3;
	auto res = pascal(num);
	std::vector<std::vector<int>> ans = { { 1 }, { 1, 1 }, { 1, 2, 1 }, { 1, 3, 3, 1 } };
	ASSERT_EQ(res, ans);
}

TEST(pascal, 4)
{
	int num = 4;
	auto res = pascal(num);
	std::vector<std::vector<int>> ans = { { 1 }, { 1, 1 }, { 1, 2, 1 }, { 1, 3, 3, 1 }, { 1, 4, 6, 4, 1 } };
	ASSERT_EQ(res, ans);
}

TEST(pascal, 5)
{
	int num = 5;
	auto res = pascal(num);
	std::vector<std::vector<int>> ans = { { 1 }, { 1, 1 }, { 1, 2, 1 }, { 1, 3, 3, 1 }, { 1, 4, 6, 4, 1 }, { 1, 5, 10, 10, 5, 1 } };
	ASSERT_EQ(res, ans);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}