//
// Created by Deepak Sahu on 1/22/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        std::stable_partition(nums.begin(), nums.end(), [](int n){return n > 0;});
        int mid = nums.size()/2;
        vector<int> result;
        int k = mid;
        for(int i =0; i < mid; i++, k++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[k]);
        }

        return result;
    }
};

//int main(void)
//{
//    vector<int> nums= {-1,1};
//    Solution().rearrangeArray(nums);
//
//}