#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numWithFreq;
        for_each(begin(nums), end(nums), [&numWithFreq](int num)
                                         {
                                            numWithFreq[num]++;
                                         });
        
        auto result = find_if(begin(numWithFreq), end(numWithFreq), [&nums](auto &numsWithFreq)
        {
            return (numsWithFreq.second) > (nums.size()/2);
        });

        return result->first;
    }
};
//int main(void)
//{
//    vector<int> nums = { 3 };
//    Solution obj;
//    obj.majorityElement(nums);
//}