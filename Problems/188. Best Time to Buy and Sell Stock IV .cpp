//
// Created by Deepak Sahu on 1/15/22.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace  std;
class Solution {
public:
    int dp[1000][101][2] = {};
    int find(vector<int> &prices, int i,int k,bool buy)
    {
        if(i>=prices.size()||k<=0) return 0;

        if(dp[i][k][buy] == 0)
            return dp[i][k][buy];
        if(buy)
        {
            return dp[i][k][buy] =max(-prices[i] + find(prices,i+1,k,!buy),
                                 find(prices,i+1,k,buy)
                                 );
        }
        else //sell
        {
            return dp[i][k][buy] =max( prices[i] + find(prices,i+1,k-1,!buy),
                                  find(prices,i+1,k,buy)
                                  );
        }
    }
//    int maxProfit(int k, vector<int>& ps) {
//        int n=ps.size();
//        return find(ps, 0, k, true, dp);
//    }
};

