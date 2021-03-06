#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int lowerbound(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }

    std::vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
        int l = lowerbound(nums, target);
        int r = lowerbound(nums, target + 1) - 1;
        if (l < nums.size() && nums[l] == target) {
            return { l,r };
        }
        return ans;
    }
};

//int main(void)
//{
//    vector<int> nums = { 5,7,7,8,8,8,10,10 };
//    Solution obj;
//    obj.searchRange(nums, 10);
//}