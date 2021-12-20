#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closesSum = 0;
        int minDiff = INT_MAX;

        for(int i =0 ; i < nums.size(); i++)
        {
            int lo = i + 1;
            int hi = nums.size() - 1;
            while(lo < hi)
            {
                int sum = nums[lo] + nums[hi] + nums[i];
                int diff = abs(target - sum);
                if(minDiff > diff)
                {
                    minDiff = diff;
                    closesSum = sum;
                }
                if(sum < target)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
            }
        }
        return closesSum;
    }
};

//int main(void)
//{
//    vector<int> nums = { -1,2,1,-4 };
//    Solution obj;
//    obj.threeSumClosest(nums, 1);
//}