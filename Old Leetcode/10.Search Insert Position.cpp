#include<iostream>
#include<vector>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

using namespace std;
class Solution {
public:
    int binarrySearch(vector<int>& nums,int low, int high,int val)
    {
        if (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == val)
            {
                return mid;
            }
            else if (nums[mid] > val)
            {
                return binarrySearch(nums, low, mid - 1, val);
            }
            else if(nums[mid] < val)
            {
                return binarrySearch(nums, mid + 1, high, val);
            }
        }
        return low;
    }

    int searchInsert(vector<int>& nums, int target) 
    {
        fastIO;
        return binarrySearch(nums, 0, nums.size() - 1, target);
    }
};

//int main(void)
//{
//    vector<int> v = { 1,3,5,6 };
//    Solution obj;
//    cout<<obj.searchInsert(v, 0);
//}