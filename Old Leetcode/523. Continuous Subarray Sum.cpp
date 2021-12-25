#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        // handling 0 case and n%0 is undefined
        if (k == 0)
        {
            int count = 0;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] == 0 && nums[i + 1] == 0)
                    return true;
            }
            return false;
        }
        //let store mod of sum and older idx as we have to have more than 2 num in subarray
        unordered_map<int, int> previousSumToIdx;
        int runningSum = 0;
        previousSumToIdx[runningSum] = -1;
        k = abs(k);
        for (int i = 0; i < nums.size(); i++)
        {
            runningSum += nums[i];
            auto it = previousSumToIdx.find(runningSum % k);
            if (it != previousSumToIdx.end())
            {
                if ((i - it->second) >= 2)
                    return true;
            }
            else
                previousSumToIdx[runningSum % k] = i;
        }
        return false;
    }
};

//int main(void)
//{
//    vector<int> nums = { 23,2,6,4,6 };
//    Solution obj;
//    cout<<obj.checkSubarraySum(nums, 2);
//}