#include <vector>
#include <iostream>

inline std::vector<std::vector<int>> pascal(int n)
{
	std::vector<std::vector<int>> dp;
	for (int i = 0; i <= n; i++) {
		std::vector<int> tmp;
		for (int j = 0; j <= i; j++) {
			tmp.push_back(1);
		}
		dp.push_back(tmp);
	}
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col < row; col++) {
			dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
		}
	}
	return dp;
}