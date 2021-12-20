#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void numsSameConsecDiffUtil(vector<int> &result,int n, int k, int currentDigit, int currentNumber )
    {
        currentNumber = currentNumber * 10 + currentDigit;
        if(n == 0)
        {
            result.push_back(currentNumber);
            return;
        }
        if(currentDigit + k < 10)
        {
            numsSameConsecDiffUtil(result, n - 1, k, currentDigit + k, currentNumber);
        }
        if(k && currentDigit - k >= 0) // if k == 0 don't explore this path because it would be same as currentDigit + k eg 1 + 0 == 1 - 0
        {
            numsSameConsecDiffUtil(result, n - 1, k, currentDigit - k, currentNumber);
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;
        if(N == 1)
        {
            return { 0,1,2,3,4,5,6,7,8,9 };
        }
        for(int i = 1 ; i < 10; i++)
        {
            numsSameConsecDiffUtil(result, N - 1, K, i, 0);
        }
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.numsSameConsecDiff(2, 1);
//}