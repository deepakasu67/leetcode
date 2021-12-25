#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool findSubsetSumEqualK(vector<int>& nums, int k, int idx, unordered_map<string, bool> &dp)
    {
        string key = to_string(k) +'|'+ to_string(idx);
        if (idx == nums.size())
        {
            if (k == 0)
            {
                dp[key] = true;
                return true;
            }
            dp[key] = false;
            return false;
        }
        if (k < 0)
        {
            dp[key] = false;
            return false;
        }
        if (k == 0)
        {
            dp[key] = true;
            return true;
        }
        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }
        bool includeThisEle = findSubsetSumEqualK(nums, k - nums[idx], idx + 1,dp);
        if (includeThisEle == true)
        {
            dp[key] = true;
            return true;
        }
        bool excludeThisEle = findSubsetSumEqualK(nums, k, idx + 1,dp);
        dp[key] = excludeThisEle || includeThisEle;
        return dp[key];
    }
    bool canPartition(vector<int>& nums) 
    {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        if (totalSum % 2 == 1)
            return false;
        totalSum = totalSum / 2;
        unordered_map<string, bool> dp;
        return findSubsetSumEqualK(nums, totalSum, 0,dp);
    }
};

//int main(void)
//{
//    vector<int> nums = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 97 };
//    Solution obj;
//   cout<<obj.canPartition(nums);
//}