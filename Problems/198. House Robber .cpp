//
// Created by Deepak Sahu on 3/3/22.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    unordered_map<int, int> dp;
public:
    int rob(vector<int>& nums, int idx)
    {
        if(idx >= nums.size())
            return 0;
        if(dp.count(idx))
            return dp[idx];
        int picked = 0;
        int notPicked = 0;
        picked += rob(nums, idx + 1);
        notPicked += nums[idx] + rob(nums, idx + 2);
        return dp[idx] = max(picked, notPicked);
    }

    int rob(vector<int>& nums) {
        return max(rob(nums, 0), rob(nums, 0));
    }
};

int main(void)
{
//    vector<int> nums = {2,7,9,3,1};
    vector<int> nums = {2,1,1,2};
    cout<<Solution().rob(nums);
}
