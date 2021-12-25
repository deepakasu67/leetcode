#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //brute-force
    //bool canReachtoEnd(vector<int>& nums, int jump, vector<int>& canReachedToEnd)
    //{
    //    if (jump >= nums.size() - 1)
    //        return true;

    //    if (canReachedToEnd[jump] != -1)
    //        return canReachedToEnd[jump];

    //    for (int i = 1; i <= min((int)nums.size() - 1, nums[jump]); i++)
    //    {
    //        if (canReachtoEnd(nums, jump + i, canReachedToEnd))
    //        {
    //            canReachedToEnd[jump] = true;
    //            return true;
    //        }
    //        canReachedToEnd[jump] = false;
    //    }
    //    return false;
    //}
    //bool canJump(vector<int>& nums)
    //{
    //    vector<int> canReachedToEnd(nums.size(), -1);
    //    return canReachtoEnd(nums, 0, canReachedToEnd);
    //}
    //bool canReachtoEnd(vector<int>& nums, int jump, vector<int>& canReachedToEnd)
    //{
    //    if (jump >= nums.size() - 1)
    //        return true;

    //    if (canReachedToEnd[jump] != -1)
    //        return canReachedToEnd[jump];

    //    for (int i = 1; i <= min((int)nums.size() - 1, nums[jump]); i++)
    //    {
    //        if (canReachtoEnd(nums, jump + i, canReachedToEnd))
    //        {
    //            canReachedToEnd[jump] = true;
    //            return true;
    //        }
    //        canReachedToEnd[jump] = false;
    //    }
    //    return false;
    //}
    //bool canJump(vector<int>& nums)
    //{
    //    vector<int> canReachedToEnd(nums.size(), -1);
    //    return canReachtoEnd(nums, 0, canReachedToEnd);
    //}

    bool canJump(vector<int>& nums)
    {
        int lastMaxReachedIdx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int maxReachedFromCur = i + nums[i];
            lastMaxReachedIdx = max(lastMaxReachedIdx, maxReachedFromCur);
            if (lastMaxReachedIdx >= n -1)
                return true;
            if (nums[i] == 0)
            {
                if (lastMaxReachedIdx <= i)
                    return false;
            }
        }
        return true;
    }
};

//int main(void)
//{
//    vector<int> nums = { 3,3,1,0,0,4 };
//    Solution obj;
//    cout<<obj.canJump(nums);
//}