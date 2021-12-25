#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        if (nums.size() < 3)
            return false;
        int smallest = INT_MAX, secondSmallest= INT_MAX;
        for(int i =0; i < nums.size(); i++)
        {
            if(nums[i] <= smallest)
            {
                smallest = nums[i];
            }
            else if(nums[i] <= secondSmallest)
            {
                secondSmallest = nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
//
//int main(void)
//{
//    vector<int> nums = {1,1,1,1};
//    Solution obj;
//    cout<<obj.increasingTriplet(nums);
//}