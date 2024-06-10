#include <vector>
#include <iostream>

std::pair<int, std::vector<int>> dfs(node& n, int max_sum, std::vector<int>& max_path)
{
	if (!n)
		return {0, std::vector<int>()};
	std::pair<int, std::vector<int>> left = dfs(node->left);
	std::pair<int, std::vector<int>> right = dfs(node->right);

	if (left.first > right.first)
		std::vector<int> current_max_path = left.left + node->data;
	else
		std::vector<int> current_max_path = left.right + node->data;

	int current_max_sum = std::max(left.first, right.first) + node->data;

	if (left.first + node->data + right.first > max_sum) {
		max_sum = left.first + node->data + right.first;
		max_path = left.second + node->data + right.second;
	}
	return {current_max_path, current_max_sum};
}

std::vector<int> find_max_path(node& root)
{
	int max_sum = 0;
	std::vector<int> max_path;
	dfs(root, max_sum, max_path);
	return max_path
}