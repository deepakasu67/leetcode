#include <algorithm>
#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> countOfRepeatedEle;
        for(int i = 0; i < nums.size(); i++)
        {
            countOfRepeatedEle[nums[i]]++;
        }
        vector<pair<int, int>> resultKeyValuePair (countOfRepeatedEle.begin(), countOfRepeatedEle.end());
        sort(resultKeyValuePair.begin(), resultKeyValuePair.end(), [](auto &l, auto &r)
        {
                if (l.second != r.second)
                    return l.second > r.second;

                return l.first < r.first;
        });
        vector<int> result;
        for(int i = 0; i < resultKeyValuePair.size() && i < k; i++)
        {
            result.push_back(resultKeyValuePair[i].first);
        }
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> nums = { 1,1,1,2,2,3,100000, 100000, 100000, 100000 };
//    obj.topKFrequent(nums, 2);
//}