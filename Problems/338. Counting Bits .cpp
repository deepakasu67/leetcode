//
// Created by Deepak Sahu on 2/28/22.
//
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> bits(n+1,0);
        int count = 0;
        for(int i = 0; i <= n; i++)
        {
            int x = i;
            count = 0;
            while(x)
            {
                count += (x & 1);
                x >>=1;
            }
            bits[i] = count;
        }
        return bits;
    }
};
//
//int main(void)
//{
//    Solution().countBits(2);
//}