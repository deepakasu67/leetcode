#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int insertAt = 0;
        int eltTOBeInserted = 0;
        while (eltTOBeInserted < nums.size())
        {
            nums[insertAt++] = nums[eltTOBeInserted];
            while (eltTOBeInserted < nums.size() - 1 && nums[eltTOBeInserted] == nums[eltTOBeInserted + 1])
            {
                eltTOBeInserted++;
            }
            eltTOBeInserted++;
        }
        return insertAt;
    }
};


//int main(void)
//{
//    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
//    Solution obj;
//    obj.removeDuplicates(nums);
//}