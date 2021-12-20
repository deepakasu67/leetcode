#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;
            if ((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target >= nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

//int main(void)
//{
//    vector<int> nums = { 1,3,1,1,1 };
//    Solution obj;
//    cout<<obj.search(nums, 3);
//}