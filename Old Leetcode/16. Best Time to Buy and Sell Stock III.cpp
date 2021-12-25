#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:

    int maxPUtil(std::vector<int>& prices, int i, int buyOrSell, int k, std::unordered_map<std::string, int>& dp) {
        if (i >= prices.size() || k == 0)
            return 0;
        std::string key = std::to_string(i) + std::to_string(buyOrSell) + std::to_string(k);
        if (dp.find(key) != dp.end()) return dp[key];
        int res = 0;
        if (buyOrSell == 0) {
            int buy = maxPUtil(prices, i + 1, 1, k, dp) - prices[i];
            int noBuy = maxPUtil(prices, i + 1, 0, k, dp);
            res += std::max(buy, noBuy);
        }
        else {
            int sell = maxPUtil(prices, i + 1, 0, k - 1, dp) + prices[i];
            int noSell = maxPUtil(prices, i + 1, 1, k, dp);
            res += std::max(sell, noSell);
        }
        dp[key] = res;
        return res;
    }

    int maxProfit(std::vector<int>& prices) {
        std::unordered_map<std::string, int> dp;
        return maxPUtil(prices, 0, 0, 2, dp);  // <prices, i, buyOrSell, k, dp>     buy-->0   sell-->1 
    }
};
