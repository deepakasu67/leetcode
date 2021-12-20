#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTarget(vector<int>& nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (target >= nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size()-1;
        int pivot = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1])
            {
                pivot = mid + 1;
                break;
            }
            else if (nums[mid] >= nums[start])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }


        if (pivot == -1) //pivot is in the first i.e ascending order
        {
            return findTarget(nums, target, 0, nums.size() - 1);
        }
        else
        {
            if (target >= nums[0] && target <= nums[pivot - 1])
            {
                return findTarget(nums, target, 0, pivot - 1);
            }
            else
            {
                return findTarget(nums, target, pivot, nums.size() - 1);
            }
        }
    }
};

//int main(void)
//{
//    vector<int> nums = { 1 ,-1};
//    Solution obj;
//    cout<<obj.search(nums,);
//}