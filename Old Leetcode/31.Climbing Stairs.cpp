#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
    int target;
    unordered_map<int, int> dp;
public:
    int climbStairsUtil(int n)
    {
        if (dp.find(n) != dp.end())
            return dp[n];
        if( n== target)
        {
            return 1;
        }
        if(n > target)
        {
            return 0;
        }
        int x = climbStairsUtil(n + 1) + climbStairsUtil(n + 2);
        dp[n] = x;
        return x;
    }
    int climbStairs(int n)
    {
        this->target = n;
        int result = climbStairsUtil(0);
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    cout<<obj.climbStairs(45);
//}