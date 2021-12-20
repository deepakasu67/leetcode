#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxProfitUtil(vector<int> prices, int idx, bool buy, unordered_map<string, int>& dp)
    {
        if (idx >= prices.size())
            return 0;

        string key = to_string(idx) + "|" + to_string(buy);

        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }


        int maxProfit = 0;
        if (buy == true)
        {
            int buy = maxProfitUtil(prices, idx + 1, false, dp) - prices[idx];
            int noBuy = maxProfitUtil(prices, idx + 1, true, dp);
            maxProfit = max(buy, noBuy);
        }
        else
        {
            int sell = maxProfitUtil(prices, idx + 2, true, dp) + prices[idx];
            int noSell = maxProfitUtil(prices, idx + 1, false, dp);
            maxProfit = max(sell, noSell);
        }
        return dp[key] = maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> dp;
        return maxProfitUtil(prices, 0, true, dp);
    }
};

//int main(void)
//{
//    vector<int> prices = { 1,2,3,0,2 };
//    Solution obj;
//    cout<<obj.maxProfit(prices);
//}