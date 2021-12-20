#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        vector<string> result;
        if (nums.empty())
        {
            if (lower == upper)
                result.push_back(to_string(lower));
            else
                result.push_back(to_string(lower) + "->" + to_string(upper));
            return result;
        }
        if (lower < nums[0])
        {
            if (lower == nums[0] - 1)
            {
                result.push_back(to_string(lower));
            }
            else
            {
                result.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
            }
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            long firstRange = nums[i];
            long secondRange = nums[i + 1];
            if (abs(secondRange - firstRange) >= 2)
            {
                long currFirstRange = firstRange + 1;
                long currSecondRange = secondRange - 1;
                if (currFirstRange != currSecondRange)
                {
                    result.push_back(to_string(currFirstRange) + "->" + to_string(currSecondRange));
                }
                else
                {
                    result.push_back(to_string(currFirstRange));
                }
            }
        }
        if (upper > nums.back())
        {
            if (upper - 1 == nums.back())
                result.push_back(to_string(nums.back()));
            else
                result.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = { -1};
//    int lower = -1;
//    int upper = -0;
//    Solution obj;
//    obj.findMissingRanges(nums, lower, upper);
//}