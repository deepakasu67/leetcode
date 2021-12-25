#include<iostream>
#include<vector>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        fastIO;
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (const auto& c : coins)
            for (int i = c; i <= amount; ++i)
                dp[i] += dp[i - c];

        return dp[amount];
    }
};