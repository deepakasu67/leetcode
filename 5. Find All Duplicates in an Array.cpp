#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> result;
        for (int orig : nums)
        {
            int num = abs(orig);
            if (nums[num - 1]  < 0)
                result.push_back(num);
            else
                nums[num-1] = nums[num-1]*-1;
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = { 4,3,2,7,8,2,3,1 };
//    Solution obj;
//    obj.findDuplicates(nums);
//}