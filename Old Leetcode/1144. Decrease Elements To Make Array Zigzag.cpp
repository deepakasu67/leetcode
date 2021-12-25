#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }

    int movesToMakeZigZagUtil(vector<int>& nums, int start)
    {
        int NumSize = nums.size();
        int result = 0;
        for (int i = start; i < NumSize; i += 2)
        {
            if (i > 0 && i < NumSize - 1)
            {
                if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1])
                {
                    result += nums[i]- min(nums[i + 1], nums[i - 1])  + 1;
                }
                else if (nums[i] >= nums[i - 1])
                {
                    result += nums[i] - nums[i - 1] + 1;
                }
                else if(nums[i] >= nums[i+1])
                {
                    result += nums[i] - nums[i + 1]+ 1;
                }

            }
            if (i == 0)
            {
                if (nums[i] >= nums[i + 1])
                    result += (nums[i] - nums[i + 1] + 1);
            }
            if (i == NumSize - 1)
            {
                if (nums[i] >= nums[i - 1])
                    result += (nums[i] - nums[i - 1] + 1);
            }
        }
        return result;
    }

    int movesToMakeZigzag(vector<int>& nums) 
    {
        int even = movesToMakeZigZagUtil(nums,0);
        int odd = movesToMakeZigZagUtil(nums, 1);
        return min(even, odd);
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> a = {10, 4, 4, 10, 10, 6, 2, 3};
//    obj.movesToMakeZigzag(a);
//}