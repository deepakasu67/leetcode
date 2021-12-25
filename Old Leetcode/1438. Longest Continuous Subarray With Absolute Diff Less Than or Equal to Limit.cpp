#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        multiset<int> maxMin;

        int left = 0;
        int longestSubarray = -1;
        for (int right = 0; right < nums.size(); right++)
        {
            maxMin.insert(nums[right]);
            int min = *maxMin.begin();
            int max = *maxMin.rbegin();

            while (max - min > limit && left < right)
            {
                auto it = maxMin.find(nums[left++]);
                maxMin.erase(it);
                min = *maxMin.begin();
                max = *maxMin.rbegin();
            }

            if (longestSubarray < right - left + 1)
            {
                longestSubarray = right - left + 1;
            }
        }
        return longestSubarray;
    }
};

//int main(void)
//{
//    vector<int> nums = { 4,2,2,2,4,4,2,2 };
//    Solution obj;
//    cout<<obj.longestSubarray(nums, 0);
//}