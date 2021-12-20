#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    unsigned int nextPowerOf2(unsigned int n)
    {
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n++;
        return n;
    }
    vector<int> countBits(int num)
    {
        vector<int> bitsCount(num + 1);
        bitsCount[0] = (0);
        if (!num)
            return bitsCount;

        bitsCount[1] = (1);
        if (num == 1)
            return bitsCount;

        unsigned int nextPwrof2 = nextPowerOf2(num);
        for (int i = 1; (1 << i) <= nextPwrof2; i++)
        {
            int start = (1 << i);
            int end = (1 << i + 1) - 1;
            int distance = end - start + 1;
            for (int j = start; j < end && j <= num; )
            {
                distance = distance / 2;
                int countDist = 0;
                for (int k = abs(j - distance); countDist < distance && j <= num; k++, countDist++)
                {
                    bitsCount[j] = bitsCount[k];
                    j++;
                }
                if (j == end && j <= num)
                {
                    bitsCount[j] = bitsCount[j - 1] + 1;
                    j++;
                }
            }
        }
        return bitsCount;
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.countBits(7);
//}