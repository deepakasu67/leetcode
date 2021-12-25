#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    map<string, int> dp;
    int helper(vector<int>& arr, int l, int r)
    {
        int max_coin = 0;
        for(int i = l+1; i < r; i++)
        {
            int score = arr[l] * arr[i] * arr[r];
            int left = helper(arr, l, i);
            int right = helper(arr, i, r);

            max_coin = max(max_coin, left + score + right);
        }
        return max_coin;
    }
    int maxCoins(vector<int>& nums)
    {
        vector<int> arr(nums.size() + 2);
        arr[0] = 1;
        arr[arr.size() - 1] = 1;
        for(int i = 1;i < arr.size()-1;i++)
        {
            arr[i] = nums[i - 1];
        }
        return helper(arr, 0, arr.size() - 1);
    }
};

//int main(void)
//{
//    vector<int> nums = { 3,1,5,8};
//    Solution obj;
//    cout<<obj.maxCoins(nums);
//}