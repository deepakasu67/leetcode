#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& numsInSorted, int target)
    {
        int l = 0, h = numsInSorted.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (numsInSorted[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        int lo = -1, hi = -1;
        sort(nums.begin(), nums.end());
        int low = lowerBound(nums, target);
        int high = lowerBound(nums, target + 1) - 1;
        if (low < nums.size() && nums[low] == target)
        {
            lo = low, hi = high;
        }
        vector<int> result;

        while (lo != -1 && lo <= hi)
        {
            result.push_back(lo);
            lo++;
        }
        return  result;
    }
};
//
//int main(void)
//{
//    vector<int> nums = { 1,2,5,2,3 };
//    int target = 6;
//    Solution().targetIndices(nums, target);
//}