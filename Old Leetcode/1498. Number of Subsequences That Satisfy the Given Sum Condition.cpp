#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target)
    {
        vector<int> power(nums.size());
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;
        int mod = 1e9 + 7;
        int count = 0;
        power[0] = 1;
        for (int i = 1; i < nums.size(); i++)
            power[i] = (power[i - 1] * 2) % mod;

        while (low <= high)
        {
            int sum = nums[low] + nums[high];
            if (sum <= target)
            {
                count = (count + power[high - low]) % mod;
                low++;
            }
            else
            {
                high--;
            }

        }
        return count;
    }
};

//int main(void)
//{
//    vector<int> nums = { 2,3,3,4,6,7 };
//    Solution obj;
//    obj.numSubseq(nums, 12);
//}