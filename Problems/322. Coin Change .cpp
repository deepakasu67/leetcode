//
// Created by Deepak Sahu on 1/16/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int,int> dp;
public:
    int helper(vector<int>& coins, int amount)
    {
        if(amount < 0)
            return -1;
        if(amount == 0)
            return 0;
        if(dp.count(amount))
        {
            return dp[amount];
        }
        int minCoins = INT_MAX - 1;
        for(int coin : coins)
        {
            if(coin <= amount)
            {
                minCoins = min(minCoins, 1+ helper(coins, amount - coin));
            }
        }
        return dp[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        int res = helper(coins, amount);
        return res == INT_MAX - 1 ? -1 : res;
    }
};

//int main(void)
//{
//    vector<int> coins = {2};
//    cout<<Solution().coinChange(coins,3);
//}
