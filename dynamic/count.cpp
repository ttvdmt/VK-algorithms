#include <vector>
#include <iostream>

inline int count(int n)
{
	std::vector<int> dp = { 1, 2, 4 };
	for (int i = 3; i <= n; i++) {
		dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
	}
	return dp[n];
}