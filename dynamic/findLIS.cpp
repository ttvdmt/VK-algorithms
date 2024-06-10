#include <vector>
#include <iostream>
#include <algorithm>

inline int findLIS(std::vector<int>& elems)
{
	if (elems.size() == 0)
		return 0;
	if (elems.size() == 1)
		return 1;

	std::vector<int> dp( elems.size(), 1 );
	for (int i = 1; i < elems.size(); i++) {
		if (elems[i - 1] < elems[i])
			dp[i] = dp[i - 1] + 1;
	}
	int res = *std::max_element(dp.begin(), dp.end());
	return res;
}