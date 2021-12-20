#include<iostream>
#include<bit>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y)
	{
        int count = 0;
        int shift = 0;
        while(x || y)
        {
            bool xbit = (x  & 1);
            bool ybit = (y  & 1);
            xbit != ybit ? count++ : count;
            x = x >> 1;
            y = y >> 1;
        }
        return count;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.hammingDistance(0, 2147483647);
//}