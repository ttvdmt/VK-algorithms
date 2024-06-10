#include "gtest/gtest.h"
#include "count.cpp"

TEST(count, empty)
{
	int num = 0;
	auto res = count(num);
	ASSERT_EQ(res, 1);
}

TEST(count, 1)
{
	int num = 1;
	auto res = count(num);
	ASSERT_EQ(res, 2);
}

TEST(count, 2)
{
	int num = 2;
	auto res = count(num);
	ASSERT_EQ(res, 4);
}

TEST(count, 3)
{
	int num = 3;
	auto res = count(num);
	ASSERT_EQ(res, 7);
}

TEST(count, 4)
{
	int num = 4;
	auto res = count(num);
	ASSERT_EQ(res, 13);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}