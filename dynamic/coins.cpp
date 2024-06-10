#include <vector>

inline int coins(std::vector<int>& coins, int amount) {
    if (amount == 0)
        return 0;

    std::vector<int> dp(amount + 1, 2'000'000);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != 2'000'000) {
                dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    return dp[amount] == 2'000'000 ? -1 : dp[amount];
}