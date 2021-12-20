#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int i = 0;
        for(i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                break;
            }
        }
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int k = 0;
        for( k = nums.size() - 1; k > i; k--)
        {
            if(nums[k] > nums[i])
            {
                break;
            }

        }
        swap(nums[i], nums[k]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};

//int main(void)
//{
//    vector<int> nums = { 3,2,1 };
//    Solution obj;
//    obj.nextPermutation(nums);
//}