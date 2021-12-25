#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int si, int k) {
        vector<int> res;
        for (int i = si; i < nums.size(); i += k) {
            auto it = std::upper_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
    int kIncreasing(vector<int>& arr, int k)
    {
        int ans = 0;
        int n = arr.size();
        int la = 0;
        for (int i = 0; i < k; i++)
        {
            if ((n - i) % k == 0)
                la = (n - i) / k;
            else
                la = ((n - i) / k) + 1;
            ans += la - lengthOfLIS(arr, i, k);
        }
        return ans;
    }
};