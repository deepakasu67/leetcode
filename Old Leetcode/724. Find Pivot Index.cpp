#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int sum = 0;
        for(int num : nums)
        {
            sum += num;
        }
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int rightSum = sum - leftSum - nums[i];

            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

//int main(void)
//{
//    vector<int> nums = { 1,7,3,6,5,6 };
//    Solution obj;
//    cout<<obj.pivotIndex(nums);
//}