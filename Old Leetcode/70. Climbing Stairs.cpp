#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    unordered_map<int, int> dp;
public:
    int climbStairs(int n) 
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        if (dp.find(n) != dp.end())
            return dp[n];
        int step1 = climbStairs(n - 1);
        int step2 = climbStairs(n - 2);
        return dp[n] = (step1 + step2);
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.climbStairs(3);
//}