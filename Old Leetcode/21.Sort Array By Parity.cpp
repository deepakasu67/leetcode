#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        for(;left < right;left++, right--)
        {
            while (left < right && nums[left] % 2 == 0) left++;
            while (left < right && nums[right] % 2 == 1) right--;
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};
//int main(void)
//{
//    vector<int> nums = { 1,2,3,4,5,6,7,8,8,9 };
//    Solution obj;
//    obj.sortArrayByParity(nums);
//}