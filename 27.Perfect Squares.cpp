#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int numSquareUtil(int n, vector<int> &dp)
    {
        if (n < 4)
            return n;
        if (dp[n] != INT_MAX)
            return dp[n];
        int count = n;
        for (int i = 1; i * i <= n; i++) {
            count = min(count, numSquareUtil(n - i * i, dp) + 1);
        }
        dp[n] = count;
        return dp[n];
    }
    int numSquares(int n) 
    {
        vector<int> dp(n + 1, INT_MAX);
        return numSquareUtil(n, dp);
    }
};
//int main(void)
//{
//    Solution obj;
//    cout<<obj.numSquares(77229);
//}