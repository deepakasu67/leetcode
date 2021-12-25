#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canReachtoEnd(vector<int>& nums, int jump, vector<int>& canReachedToEnd)
    {
        if (jump >= nums.size() - 1)
            return 0;

        if (nums[jump] == 0)
            return INT_MAX;

        if (canReachedToEnd[jump] != -1)
            return canReachedToEnd[jump];

        int mini = INT_MAX;
        for (int i = 1; i <= min((int)nums.size() - 1, nums[jump]); i++)
        {
            int stepToReachWIthIthStep = min(mini, canReachtoEnd(nums, jump + i, canReachedToEnd));
            if (stepToReachWIthIthStep != INT_MAX)
            {
                mini =  min(mini, stepToReachWIthIthStep);
            }
        }
        return canReachedToEnd[jump] = (mini == INT_MAX ? INT_MAX : mini + 1);
    }
    int canJump(vector<int>& nums)
    {
        vector<int> canReachedToEnd(nums.size(), -1);
        return canReachtoEnd(nums, 0, canReachedToEnd);
    }
};

//int main(void)
//{
//    vector<int> nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
//    Solution obj;
//    cout<<obj.canJump(nums);
//}