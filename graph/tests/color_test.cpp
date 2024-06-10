#include "gtest/gtest.h"
#include "color.cpp"

TEST(find_connection_comp, easy)
{
	std::vector<std::vector<int>> graph = { {} };
	auto res = find_connection_comp(graph);
	std::unordered_map<int, int> ans;
	ans[0] = 1;
	ASSERT_EQ(res, ans);
}

TEST(find_connection_comp, medium)
{
	std::vector<std::vector<int>> graph = { {1}, {0} };
	auto res = find_connection_comp(graph);
	std::unordered_map<int, int> ans;
	ans[0] = 1;
	ans[1] = 1;
	ASSERT_EQ(res, ans);
}

TEST(find_connection_comp, hard)
{
	std::vector<std::vector<int>> graph = { {1, 2} , {0, 2} , {0, 1}, {5, 6}, {5, 6}, {3, 4, 6}, {3, 4, 5}, {10}, {9, 10}, {8}, {7, 8} };
	auto res = find_connection_comp(graph);
	std::unordered_map<int, int> ans;
	ans[0] = 1;
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 2;
	ans[4] = 2;
	ans[5] = 2;
	ans[6] = 2;
	ans[7] = 3;
	ans[8] = 3;
	ans[9] = 3;
	ans[10] = 3;
	ASSERT_EQ(res, ans);
}

int main()
{
	testing::InitGoogleTest();
	auto result = RUN_ALL_TESTS();
	std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
}