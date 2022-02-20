//
// Created by Deepak Sahu on 1/30/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() , nums.begin() + k);
        reverse(nums.begin()+k, nums.end());
    }
};

//int main(void)
//{
//    vector<int> nums = {1,2,3,4,5,6,7};
//    Solution().rotate(nums,3);
//    cout<<string(nums.begin(), nums.end());
//}
