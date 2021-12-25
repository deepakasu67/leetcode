#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(n^2logn)
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> result;
//        int numsSize = nums.size();
//        int a = 0;
//        int b;
//        for (int i = 0; i < numsSize - 2; i++)
//        {
//            if (i!=0 && nums[i-1] == nums[i])
//            {
//                continue;
//            }
//             a = i;
//             b = a + 1;
//             while (b < numsSize)
//             {
//                 int c = -1 * (nums[a] + nums[b]);
//                 if (binary_search(nums.begin() + b + 1, nums.end(), c))
//                 {
//                     result.push_back(vector<int>{nums[a], nums[b], c});
//                 }
//                 while (++b < numsSize && nums[b - 1] == nums[b]);
//             }
//        }
//        return result;
//    }
//};
//O(n^2)
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        fastIO;
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int numSize = nums.size();
        for (int i = 0; i < numSize - 2; i++)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            int b = i + 1;
            int c = numSize - 1;
            while (b < c)
            {
                int target = (nums[i] + nums[b] + nums[c]);
                if (target == 0)
                {
                    result.push_back({ nums[i], nums[b],nums[c] });
                    while (++b < numSize && nums[b - 1] == nums[b]);
                    while (--c > b && nums[c + 1] == nums[c]);
                }
                else if (target < 0)
                {
                    b++;
                }
                else if (target > 0)
                    c--;
            }
        }
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> nums = { -1,0,1,2,-1,-4 };
//    obj.threeSum(nums);
//}
