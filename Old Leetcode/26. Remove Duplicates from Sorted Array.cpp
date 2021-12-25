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
        int countOfEltToBeInserted = 0;
        while (eltTOBeInserted < nums.size())
        {
            countOfEltToBeInserted = 0;
            while (eltTOBeInserted < nums.size() - 1 && nums[eltTOBeInserted] == nums[eltTOBeInserted + 1])
            {
                eltTOBeInserted++;
                countOfEltToBeInserted++;
            }
            if (eltTOBeInserted >= nums.size())
                break;
            if (countOfEltToBeInserted >= 1 )
            {
                nums[insertAt++] = nums[eltTOBeInserted];
                nums[insertAt++] = nums[eltTOBeInserted];
            }
            else
            {
                nums[insertAt++] = nums[eltTOBeInserted];
            }
            eltTOBeInserted++;
        }
        return insertAt;
    }
};

//
//int main(void)
//{
//    vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
//    Solution obj;
//    obj.removeDuplicates(nums);
//}