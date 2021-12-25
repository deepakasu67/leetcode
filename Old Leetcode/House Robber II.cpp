#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int robHelper(vector<int>& nums, int start, int end)
    {
        vector<int> dp(end - start + 1);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i < end; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end - 1];
    }
    int rob(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        return max(robHelper(nums, 0, nums.size() - 1), robHelper(nums, 1, nums.size()));

    }
};

//int main(void)
//{
//    vector<int> nums{ 1,2,3,1 };
//    Solution obj;
//    cout<<obj.rob(nums);
//}