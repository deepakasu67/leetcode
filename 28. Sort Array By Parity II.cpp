#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] % 2 == 0)
            {
                while (left < right)
                {
                    if (nums[right] % 2 != 0)
                    {
                        swap(nums[left], nums[right]);
                        right--;
                        break;
                    }
                    right--;
                }
            }
            left++;
        }

        left = 0;
        right = nums.size() - 1;

        while (left < right)
        {
            swap(nums[left], nums[right]);
            left += 2, right -= 2;
        }

        return nums;
    }
};

//int main(void)
//{
//    vector<int> nums = {2, 3, 1, 1, 4, 0, 0, 4, 3, 3};
//    Solution obj;
//    obj.sortArrayByParityII(nums);
//}