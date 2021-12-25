#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> isRemainingPresent;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (isRemainingPresent.find(target - nums[i]) != isRemainingPresent.end())
            {
                return { isRemainingPresent[target - nums[i]], i };
            }
            isRemainingPresent.insert({nums[i], i });
        }
        return { 0,0 };
    }
};

//int main(void)
//{
//    vector<int> nums = { 2,7,11,15 };
//    int target = 9;
//    Solution obj;
//    auto indices = obj.twoSum(nums, target);
//}

