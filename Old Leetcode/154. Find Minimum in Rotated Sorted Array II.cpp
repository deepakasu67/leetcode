#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[right] == nums[mid])
                right--;
            else
                right = mid ;
        }
        return nums[right];
    }
};

//int main(void)
//{
//    //vector<int> nums = { 3,4,5,6,7,8,9,0,1 };
//    //vector<int> nums = {9,8,7,6,5,4,3,2,1};
//    vector<int> nums = { 1, 2, 1 };
//    Solution obj;
//    cout<<obj.findMin(nums);
//}