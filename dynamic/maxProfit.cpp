#include <iostream>
#include <vector>

inline int maxProfit(std::vector<int>& prices)
{
	if (prices.size() == 0)
		return 0;

	int profit = 0;
	int min_price = prices[0];

	for (int cur = 1; cur < prices.size(); cur++) {
		profit = std::max(profit, prices[cur] - min_price);
		min_price = std::min(prices[cur], min_price);
	}
	return profit;
}