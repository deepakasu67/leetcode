#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> result;
        for(int i = 0 ; i < nums.size();i++)
        {
            int orig = nums[i] < 0 ? -1 * nums[i] : nums[i];
            if(nums[orig - 1] < 0) //seen before
            {
                result.push_back(orig);
            }
            else
            {
                nums[orig - 1] = -nums[orig - 1];
            }
        }
        return result;
    }
};
//int main(void)
//{
//    vector<int> nums = { 2,2,3,3,4,4,1,1 };
//    Solution obj;
//    obj.findDuplicates(nums);
//}