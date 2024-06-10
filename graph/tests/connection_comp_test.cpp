#include "gtest/gtest.h"
#include "connection_comp.cpp"

TEST(find_connection_comp, easy)
{
	std::vector<std::vector<int>> graph = { {} };
	int start = 0;
	auto res = find_connection_comp(graph);
	ASSERT_EQ(res, std::vector<std::vector<int>>{ {0} });
}

TEST(find_connection_comp, medium)
{
	std::vector<std::vector<int>> graph = { {1}, {0} };
	auto res = find_connection_comp(graph);
	std::vector<std::vector<int>> ans = { {0, 1} };
	ASSERT_EQ(res, ans);
}

TEST(find_connection_comp, hard)
{
	std::vector<std::vector<int>> graph = { {1, 2} , {0, 2} , {0, 1}, {5, 6}, {5, 6}, {3, 4, 6}, {3, 4, 5}, {10}, {9, 10}, {8}, {7, 8} };
	int start = 0;
	auto res = find_connection_comp(graph);
	std::vector<std::vector<int>> ans = { { 0, 1, 2 }, { 3, 5, 4, 6 }, { 7, 10, 8, 9 } };
	ASSERT_EQ(res, ans);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}