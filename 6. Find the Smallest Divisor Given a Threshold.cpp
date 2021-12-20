#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int sumOfAllQuotientOfArr(vector<int>& nums, int divisor)
    {
        int sum = 0;
        for(int i = 0 ;i < nums.size(); i++)
        {
            sum += ceil(static_cast<double>(nums[i]) / static_cast<double>(divisor));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int lowDiv = 0;
        int highDiv = *max_element(nums.begin(),nums.end());
        while(lowDiv < highDiv)
        {
            int midDiv = lowDiv + (highDiv - lowDiv) / 2;
            if(midDiv == 0)
                break;
            int sumOfAllQuotient = sumOfAllQuotientOfArr(nums, midDiv);
            if(sumOfAllQuotient > threshold)
            {
                lowDiv = midDiv + 1;
            }
            else if(sumOfAllQuotient <= threshold)
            {
                highDiv = midDiv;
            }
        }
        return lowDiv  > 0 ? lowDiv : 1;
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<int> nums = { 962551,933661,905225,923035,990560 };
//    cout<<obj.smallestDivisor(nums, 10);
//}