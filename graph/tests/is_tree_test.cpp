#include "gtest/gtest.h"
#include "is_tree.cpp"

TEST(is_tree, easy)
{
	std::vector<std::vector<int>> graph = {{1}};
	int start = 0;
	auto res = is_tree(graph, start);
	ASSERT_EQ(res, true);
}

TEST(is_tree, medium)
{
	std::vector<std::vector<int>> graph = { {0, 1, 2}, {1, 0, 3}, {2, 3, 0} };
	int start = 0;
	auto res = is_tree(graph, start);
	ASSERT_EQ(res, false);
}

TEST(is_tree, hard)
{
	std::vector<std::vector<int>> graph = { {0, 1, 5, 0}, {1, 0, 2, 3}, {5, 2, 0, 1}, {0, 3, 1, 0} };
	int start = 0;
	auto res = is_tree(graph, start);
	ASSERT_EQ(res, false);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}