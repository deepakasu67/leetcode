#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    int maxProfitUtil(vector<int>& prices, bool buy,int idx, map<string,int> &dp)
    {
        if (idx >= prices.size())
            return 0;

        string key = to_string(idx) + "|" + to_string((int)buy);
        if (dp.find(key) != dp.end())
            return dp[key];
        int x = 0;
        if(buy == true)
        {
            int noBuy = maxProfitUtil(prices, true, idx + 1, dp);
            int buy = maxProfitUtil(prices, false, idx + 1, dp) - prices[idx];
            x = max(noBuy, buy);
        }
        else
        {
            int noSell = maxProfitUtil(prices, false, idx + 1, dp);
            int sell = maxProfitUtil(prices, true, idx + 2, dp) + prices[idx];
            x = max(sell, noSell);
        }
        dp.insert(make_pair(key,x));
        return x;
    }
    int maxProfit(vector<int>& prices)
    {
        map<string, int> dp;
        return maxProfitUtil(prices, true, 0,dp);
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> prices = { 1,2,3,0,2 };
//    cout<<obj.maxProfit(prices);
//}