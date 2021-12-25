#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:

    int maxPUtil(vector<int>& prices, int i, int buyOrSell, int k, unordered_map<string, int>& dp) {
        if (i >= prices.size() || k == 0)
            return 0;
        string key = to_string(i) + to_string(buyOrSell) + to_string(k);
        if (dp.find(key) != dp.end()) return dp[key];

        int noTransaction = maxPUtil(prices, i + 1, buyOrSell, k, dp);
        int res = 0;
        if (buyOrSell == 0) {
            res = maxPUtil(prices, i + 1, 1, k - 1, dp) - prices[i];
        }
        else {
            res = maxPUtil(prices, i + 1, 0, k - 1, dp) + prices[i];
        }
        dp[key] = max(res, noTransaction);
        return res;
    }

    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> dp;
        return maxPUtil(prices, 0, 0, 4, dp);  // <prices, i, buyOrSell, k, dp>     buy-->0   sell-->1 
    }
};
//int main(void)
//{
//    vector<int> prices = { 3,3,5,0,0,3,1,4 };
//    Solution obj;
//    cout<<obj.maxProfit(prices);
//}