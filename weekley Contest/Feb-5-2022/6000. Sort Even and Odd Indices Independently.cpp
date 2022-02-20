//
// Created by Deepak Sahu on 2/5/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums)
    {
        vector<int> evenIdxNum, oddIdxNum;

        for(int i =0;i < nums.size(); i++)
        {
            if(i %2 == 0)
                evenIdxNum.push_back(nums[i]);
            else
                oddIdxNum.push_back(nums[i]);
        }
        std::sort(evenIdxNum.begin(), evenIdxNum.end());
        std::sort(oddIdxNum.begin(), oddIdxNum.end(), greater<int>());

        vector<int> result;
        bool evenTurn = true;
        for(int  i=0, j=0;i < evenIdxNum.size() || j < oddIdxNum.size(); )
        {
            if( evenTurn)
            {
                result.push_back(evenIdxNum[i++]);
                evenTurn = !evenTurn ;
            }
            else
            {
                result.push_back(oddIdxNum[j++]);
                evenTurn = !evenTurn;
            }
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = {4,1,2,3};
//    Solution().sortEvenOdd(nums);
//}
