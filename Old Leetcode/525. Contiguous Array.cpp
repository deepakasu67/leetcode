#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int j = 0;
        int zeros = 0;
        int ones = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeros++;
            }
            if (nums[i] == 1)
            {
                ones++;
            }
            if (zeros == ones)
            {
                result++;
                while (zeros == ones && j < i)
                {
                    if (nums[j] == 0)
                        zeros--;
                    if (nums[j] == 1)
                        ones--;
                    j++;
                }
            }
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = { 1,1,1,1,0,1,1,0 };
//    Solution obj;
//    obj.findMaxLength(nums);
//}
