#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int lead = 0;
        int trail = 0;
        int maxLengthTillNow = 0;
        for (; lead < A.size(); lead++)
        {
            if (A[lead] == 0)
            {
                K--;
            }
            while (K < 0 && lead >= trail)
            {
                if (A[trail] == 0)
                {
                    K++;
                }
                trail++;
            }
            maxLengthTillNow = max(maxLengthTillNow, lead - trail + 1);
        }
        return maxLengthTillNow;
    }
};

//int main(void)
//{
//    vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
//    Solution obj;
//    obj.longestOnes(nums, 2);
//}