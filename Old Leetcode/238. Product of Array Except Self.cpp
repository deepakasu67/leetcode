#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> productFromLeftToRight(nums.size());
        vector<int> productFromRightToLeft(nums.size());

        for(int i = nums.size() - 1; i >= 0;i--)
        {
            if(i == nums.size() - 1)
            {
                productFromRightToLeft[i] = nums[i];
            }
            else
            {
                productFromRightToLeft[i] = productFromRightToLeft[i + 1] * nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                productFromLeftToRight[i] = nums[i];
            }
            else
            {
                productFromLeftToRight[i] = productFromLeftToRight[i - 1] * nums[i];
            }
        }

        vector<int> result;
        for(int i = 0 ;i < nums.size();i++)
        {
            int numToBeInserted = 0;
            if(i == 0)
            {
                numToBeInserted = productFromRightToLeft[i + 1];
            }
            else if(i == nums.size() - 1)
            {
                numToBeInserted = productFromLeftToRight[i - 1];
            }
            else
            {
                numToBeInserted = productFromRightToLeft[i + 1] * productFromLeftToRight[i - 1];
            }
            result.push_back(numToBeInserted);
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = { 1,2,3,4 };
//    Solution obj;
//    obj.productExceptSelf(nums);
//}