#include<iostream>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K)
    {
        if(K%2 == 0)
        {
            return -1;
        }
        if (K % 5 == 0)
            return -1;
        int temp = K;
        int firstResultNum = 0;
        int lengthOfDigit = 0;
        while(temp)
        {
            temp = temp / 10;
            firstResultNum = firstResultNum * 10 + 1;
            lengthOfDigit++;
        }
        if(firstResultNum < K)
        {
            firstResultNum = firstResultNum * 10 + 1;
            lengthOfDigit ++ ;
        }
        while(firstResultNum%K != 0)
        {
            lengthOfDigit++;
            firstResultNum = firstResultNum % K;
            firstResultNum = firstResultNum * 10 + 1;
        }
        return lengthOfDigit;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout << obj.smallestRepunitDivByK(19);
//}
