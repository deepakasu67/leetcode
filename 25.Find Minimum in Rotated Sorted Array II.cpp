#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//    int findMinUtil(vector<int>& nums, int l, int r)
//    {
//        if(r >= l)
//        {
//
//            int mid = l + (r - l) / 2;
//            if (mid > 0 && mid < nums.size() - 1 && (nums[mid] < nums[mid - 1] || nums[mid] > nums[mid + 1]))
//            {
//                if (nums[mid] < nums[mid - 1])
//                    return mid;
//                if (nums[mid] > nums[mid + 1])
//                    return mid + 1;
//            }
//            if (l != r && nums[mid] == nums[l] && nums[mid] == nums[r])
//                return findMinUtil(nums, l + 1, r - 1);
//            bool leftRecur = true;
//            if(nums[mid] > nums[l] && nums[mid] > nums[r])
//            {
//                leftRecur = false;
//            }
//            if (nums[mid] == nums[l])
//                leftRecur = false;
//
//
//            if(leftRecur)
//            {
//                return findMinUtil(nums, l, mid - 1);
//            }
//            else
//            {
//                return findMinUtil(nums, mid + 1, r);
//            }
//        }
//        return -1;
//    }
//    int findMin(vector<int>& nums)
//    {
//        if (nums.size() == 1)
//            return nums[0];
//        if (nums.size() == 2)
//            return min(nums[0], nums[1]);
//        if (nums[0] < nums[nums.size() - 1])
//            return nums[0];
//        
//        int idx = findMinUtil(nums, 0, nums.size() - 1);
//        return idx == -1 ?  nums[0]: nums[idx];
//    }
//};
class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {
            int m = (low + high) / 2;

            if (nums[high] < nums[m])
            {
                low = m + 1;
            }
            else if (nums[high] > nums[m])
            {
                high = m;
            }
            else
            {
                high--;
            }
        }
        return nums[low];
    }
};
//int main(void)
//{
//    //{ 4,5,6,7,0,1,2 }; { 7,0,1,2,4,5,6 }
//    vector<int> vec = { 2,1,1,2,2,2,2 };
//    // { 10,10,10,10,10 };
//   /*{ 0,1,2,4,5,6,7 }*/
//    Solution obj;
//    obj.findMin(vec);
//}