#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int idxOfZero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                idxOfZero = i;
                break;
            }
        }
        for (int j = idxOfZero + 1; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                swap(nums[j], nums[idxOfZero]);
                idxOfZero++;
                while (idxOfZero > nums.size() && nums[idxOfZero] != 0) idxOfZero++;
            }
        }
    }
};

//int main(void)
//{
//    vector<int> nums = { 0,1,0,3,12 };
//    Solution obj;
//    obj.moveZeroes(nums);
//}