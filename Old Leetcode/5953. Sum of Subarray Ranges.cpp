#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums, int i, int j, vector<vector<bool>>& dp)
    {
        if (i < 0 || i >= nums.size() || j < 0 || j >= nums.size()|| dp[i][j] == true || i > j)
        {
            return 0;
        }
        dp[i][j] = true;
        int minNum = *min_element(nums.begin() + i, nums.begin()+ j+1);
        int maxNum = *max_element(nums.begin() + i, nums.begin() + j+1);

        int current = maxNum - minNum;

        return current + subArrayRanges(nums, i + 1, j,dp) + subArrayRanges(nums, i, j - 1,dp);

    }
    long long subArrayRanges(vector<int>& nums) 
    {
        vector<vector<bool>> dp(nums.size(), vector<bool>(nums.size(), 0));
        return subArrayRanges(nums, 0, nums.size() - 1, dp);
    }
};

//int main(void)
//{
//    vector<int> nums = { 4,-2,-3,4,1 };
//    cout<<Solution().subArrayRanges(nums);
//}