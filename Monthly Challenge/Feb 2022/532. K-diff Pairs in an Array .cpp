//
// Created by Deepak Sahu on 2/9/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), greater<int>());
        unordered_set<int> found;
        int count = 0;
        bool duplicate = true;
        for(int i =0; i < nums.size(); i++)
        {
            if(i != 0 && nums[i-1] == nums[i] ) {
                if(k == 0 && duplicate)
                    count++;
                duplicate = false;
                continue;
            }
            duplicate = true;
            int secEle = k + nums[i];
            if(found.count(secEle))
            {
                count++;
            }
            found.insert(nums[i]);
        }
        return count;
    }
};

//int main(void)
//{
//    vector<int> nums = {1,1,1,1,1};
//    int k = 0;
//    cout<<Solution().findPairs(nums, k);
//}