#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (abs(nums[0]) > abs(nums[i]))
            {
                swap(nums[0], nums[i]);
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        return nums;
    }
};

//int main(void)
//{
//    vector<int> arr = { -2,-1,0,3,10 };
//    Solution obj;
//    obj.sortedSquares(arr);
//}