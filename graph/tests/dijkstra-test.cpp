#include "gtest/gtest.h"
#include "dijkstra.cpp"

TEST(dijkstra, easy)
{
	std::vector<std::vector<int>> graph = { {0, 2}, {2, 0} };
	int start = 0;
	auto res = dijkstra(graph, start);
	std::unordered_map<std::vector<int>, int> ans;
	ans[std::vector<int>{0, 2}] = 0;
	ans[std::vector<int>{2, 0}] = 2;
	ASSERT_EQ(res, ans);
}

TEST(dijkstra, medium)
{
	std::vector<std::vector<int>> graph = { {0, 1, 2}, {1, 0, 3}, {2, 3, 0} };
	int start = 0;
	auto res = dijkstra(graph, start);
	std::unordered_map<std::vector<int>, int> ans;
	ans[std::vector<int>{0, 1, 2}] = 0;
	ans[std::vector<int>{1, 0, 3}] = 1;
	ans[std::vector<int>{2, 3, 0}] = 2;
	ASSERT_EQ(res, ans);
}

TEST(dijkstra, hard)
{
	std::vector<std::vector<int>> graph = { {0, 1, 5, 0}, {1, 0, 2, 3}, {5, 2, 0, 1}, {0, 3, 1, 0} };
	int start = 0;
	auto res = dijkstra(graph, start);
	std::unordered_map<std::vector<int>, int> ans;
	ans[std::vector<int>{ 0, 1, 5, 0 }] = 0;
	ans[std::vector<int>{ 1, 0, 2, 3 }] = 1;
	ans[std::vector<int>{ 5, 2, 0, 1 }] = 3;
	ans[std::vector<int>{ 0, 3, 1, 0 }] = 4;
	ASSERT_EQ(res, ans);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}