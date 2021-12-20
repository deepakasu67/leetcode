#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //this will not work for -ve elements
    //int subarraySum(vector<int>& nums, int k)
    //{
    //    if (nums.empty())
    //    {
    //        return 0;
    //    }

    //    int minElt = *min_element(nums.begin(), nums.end());
    //    if(minElt < 0)
    //    {
    //        int addElt = -1 * minElt;

    //        for(int i = 0 ;i < nums.size(); i++)
    //        {
    //            nums[i] += addElt;
    //        }
    //        k+=addElt;
    //    }
    //    
    //    int lead = 0;
    //    int trail = 0;
    //    int runningSum = 0;
    //    int countSubArraySum = 0;
    //    for (lead = 0; lead < nums.size(); lead++)
    //    {
    //        runningSum += nums[lead];

    //        if (runningSum == k)
    //        {
    //            countSubArraySum++;
    //        }
    //        if (runningSum > k)
    //        {
    //            while (trail <= lead)
    //            {
    //                if (runningSum > k)
    //                {
    //                    runningSum -= nums[trail];
    //                }
    //                else if (runningSum == k)
    //                {
    //                    countSubArraySum++;
    //                    runningSum -= nums[trail];
    //                }
    //                else
    //                    break;

    //                trail++;
    //            }
    //        }
    //    }
    //    return countSubArraySum;
    //}
    int subarraySum(vector<int>& nums, int k)
    {
        int runningSum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            runningSum += nums[i];
            if (prefixSum.find((runningSum - k)) != prefixSum.end())
            {
                result += prefixSum[runningSum - k];
            }
            prefixSum[runningSum] = prefixSum[runningSum] + 1;
        }
        return result;
    }
};


//int main(void)
//{
//    vector<int> nums = { 1,1,1 };
//    Solution obj;
//    obj.subarraySum(nums, 2);
//}

