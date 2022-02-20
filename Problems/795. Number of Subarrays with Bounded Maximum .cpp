//
// Created by Deepak Sahu on 12/31/21.
//
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int countTheSubarray(int n)
    {
        return n*(n+1)/2;
    }
    int countSubarrayInRange(vector<int>& nums, int range)
    {
        int l = -1;
        int ans = 0;
        int r = 0;
        while(l < r && r < nums.size())
        {
            if(nums[r] > range)
            {
                ans+= countTheSubarray(r-l-1);
                l = r;
            }
            r++;
        }
        if(nums.back() <= range)
        {
            ans += countTheSubarray(r-l-1);
        }
        return ans;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right)
    {
        return countSubarrayInRange(nums,right) - countSubarrayInRange(nums, left-1);
    }
};
//int main(void)
//{
//    //vector<int> nums = {2,1,4,3};
//    //vector<int> nums = {7,3,6,7,1};
//    vector<int> nums = {73,55,36,5,55,14,9,7,72,52};
//
//	cout<<Solution().numSubarrayBoundedMax(nums, 32, 69);
//}
