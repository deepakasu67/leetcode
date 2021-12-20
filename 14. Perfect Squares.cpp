#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int numSquares(int n)
    {
        if (n < 0)
            return INT_MAX;
        if (n == 0)
            return 0;
        if (dp.find(n) != dp.end())
            return dp[n];

        int leastPerfectSquares = INT_MAX;
        for (int i = 1; i <= min(100, n/2+1); i++)
        {
            int square = i * i;
            if (square <= n)
            {
                leastPerfectSquares = min(leastPerfectSquares, 1+ numSquares(n - square));
            }
        }
        return dp[n] = leastPerfectSquares;
    }
};
//
//int main(void)
//{
//    Solution obj;
//    cout<<obj.numSquares(13);
//}