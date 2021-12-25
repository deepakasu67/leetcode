//https://www.youtube.com/watch?v=3TSC0nlur58
// 1. first xor all the number
// 2. then we will take any set bit from right or left
// 3. then we will check that set bit wth each number.. whoever matches with that then we will put it into one group
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xorSum = 0;
        for (auto const& n : nums)
        {
            xorSum ^= n;
        }
        int lowSetBit = (xorSum & -xorSum);
        vector<int> res{ 0, 0 };
        for (auto const& n : nums)
        {
            if (n & lowSetBit)
                res[0] ^= n; // as only one number would be in this set which is unique
            else
                res[1] ^= lowSetBit;
        }
        return res;
    }
};
//int main(void)
//{
//    vector<int> v = { 1,2,1,3,2,5 ,3, 6 };
//    //vector<int> v = {0,1,2,2};
//    
//    Solution obj;
//    obj.singleNumber(v);
//}