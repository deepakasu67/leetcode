//consider this array form a loop if we consider the array value as next element
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int tor = nums[0];
        do
        {
            tor = nums[tor];
            hare = nums[nums[hare]];
        } while (hare != tor);

        tor = nums[0];
        while (tor != hare)
        {
            hare = nums[hare];
            tor = nums[tor];

        }

        return hare;
    }

    /*int findDuplicate(vector<int>& nums)
    {
        // The idea is that it is known that there is a duplicate, so 
        // we can use pigeon hole concept here. We do binary search on the search
        // space of [1:N], then count the number of elements <= middle. If the 
        // duplicate is on the left side, then count should be more than mid,
        // else it is on the right side. Initially search space is [1: N], then
        // each time narrow down the search space
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            // count the number of elements smaller/ equal than middle element
            int c = 0;
            for (const int& el : nums)
                if (el <= mid)
                    ++c;

            if (c > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }*/
};
//int main(void)
//{
//    Solution obj;
//    vector<int> v = { 1,3,4,2,3 };
//    cout<<obj.findDuplicate(v);
//    
//}