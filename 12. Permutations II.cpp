#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
class Solution {
public:

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        if(nums.size() <= 1)
        {
            return {nums};
        }
        unordered_set<vector<int>, VectorHash> resultForRemaining;
        for(int i = 0; i < nums.size();i++)
        {
            int curr = nums[i];
            vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto res = permuteUnique(v);
            for(int j = 0; j < res.size();j++)
            {
                vector<int> _v = res[j];
                _v.insert(_v.begin(), curr);
                resultForRemaining.insert(_v);
            }
        }
        return { resultForRemaining.begin(), resultForRemaining.end() };
    }
};
//int main(void)
//{
//    vector<int> nums = {2,2,1,1};
//    Solution obj;
//    auto result = obj.permuteUnique(nums);
//}
