#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxConsecutiveOnesLength = 0;
        int currentWindowLength = 0;
        int left = 0;
        int right = 0;
        for (; right < nums.size(); right++)
        {
            if (nums[right] == 0)
            {
                currentWindowLength = 0;
                left = right + 1;
            }
            else 
            {
                currentWindowLength = right - left + 1;
                maxConsecutiveOnesLength = max(currentWindowLength, maxConsecutiveOnesLength);
            }
        }

        return maxConsecutiveOnesLength;
    }
};
//int main(void)
//{
//    vector<int> ones = { 1,1,1,1,1,0,1,1,1,1,1,1,1,0 };
//    Solution obj;
//    cout<<obj.findMaxConsecutiveOnes(ones);
//}