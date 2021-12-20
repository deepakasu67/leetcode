#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int, int> numsToCount;
        int count = 0;
        for(int i = 0 ;i < nums.size(); i++)
        {
            if(numsToCount.find(k - nums[i]) != numsToCount.end())
            {
                count++;
                numsToCount[k - nums[i]]--;
            }
            else
            {
                numsToCount[nums[i]]++;
            }
            if(numsToCount[k - nums[i]] == 0)
            {
                numsToCount.erase(k - nums[i]);
            }
        }
        return count;
    }
};
//
//int main(void)
//{
//    vector<int> nums = { 1,2,3,4,5 };     
//    Solution obj;
//    obj.maxOperations(nums, 5);
//}