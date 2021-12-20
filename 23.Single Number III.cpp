#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int xorSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorSum ^= nums[i];
        }
        int lowSetBit = (xorSum & -xorSum);
        vector<int> result(2);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & lowSetBit)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> vec = { 1, 2, 1, 3, 2, 5 };
//    obj.singleNumber(vec);
//}