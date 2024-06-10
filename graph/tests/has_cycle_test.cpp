#include "gtest/gtest.h"
#include "has_cycle.cpp"

TEST(dijkstra, easy)
{
	std::vector<std::vector<int>> graph = { {0} };
	auto res = has_cycle(graph);
	ASSERT_EQ(res, false);
}

TEST(dijkstra, medium)
{
	std::vector<std::vector<int>> graph = { {0, 1}, {1, 0} };
	auto res = has_cycle(graph);
	ASSERT_EQ(res, true);
}

TEST(dijkstra, hard)
{
	std::vector<std::vector<int>> graph = { {0, 1, 1}, {1, 0, 1}, {1, 1, 0} };
	auto res = has_cycle(graph);
	ASSERT_EQ(res, true);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}