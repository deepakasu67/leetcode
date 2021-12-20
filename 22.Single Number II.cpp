// C++ program to find XOR without using ^ 
#include <iostream> 
#include<vector>
using namespace std;
class Solution {
public:
    //int singleNumber(vector<int>& nums) 
    //{
    //    int bits[32];;
    //    for(int i = 0 ; i < 32; i++)
    //    for (const auto& n : nums)
    //    {
    //        bits[i] += n >> i & 1;
    //        bits[i] %= 3;
    //    }
    //    int result = 0;
    //    for (int i = 0; i < 32; i++)
    //    {
    //        result |= (bits[i] << i);
    //    }
    //    return result;
    //}
    //https://www.youtube.com/watch?v=ZbTXZ2_YAgI
    int singleNumber(vector<int>& nums)
    {
        int ones = 0, twos = 0, thrice = 0;
        for (int n : nums)
        {
            twos = twos | (ones & n); 
            ones = ones ^ n;
            thrice = ones & twos;
            ones &= ~thrice;
            twos &= ~thrice;
        }
        return ones;
    }
};