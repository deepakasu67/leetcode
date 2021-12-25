#include<iostream>
#include<bitset>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> bits(n);
        int left = 0;
        int right = 31;
        while(left < right)
        {
            bitset<1> b(bits[left]);
            bits[left] = bits[right];
            bits[right] = b[0];
            left++;
            right--;
        }
        return static_cast<uint32_t>(bits.to_ulong());;
    }
};
//int main(void)
//{
//    Solution obj;
//    cout<<obj.reverseBits(4294967293);
//}