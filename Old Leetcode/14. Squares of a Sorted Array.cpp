#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            if(abs(nums[left]) < abs(nums[right]))
            {
                result.push_back(nums[right]);
                right--;
            }
            else if(abs(nums[left]) > abs(nums[right]))
            {
                result.push_back(nums[left]);
                left++;
            }
            else
            {
                result.push_back(nums[left]);
                result.push_back(nums[right]);
                left++; right--;
            }
        }
        if(left == right)
            result.push_back(nums[left]);
        for(int i =0;i < result.size();i++)
        {
            result[i] = result[i] * result[i];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = { -10000,-9999,-7,-5,0,0,10000 };
//    Solution obj;
//    obj.sortedSquares(nums);
//}