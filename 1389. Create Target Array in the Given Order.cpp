#include<iostream>
#include<deque>
#include<vector>
#include<list>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int len = nums.size();
        list<int> result;
        list<int>::iterator it = result.begin();
        for (int i = 0; i < len; i++)
        {
            advance(it,index[i]);
            result.insert(it, nums[i]);
            it = result.begin();
        }
        vector<int> output(result.begin(), result.end());
        return output;
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<int> nums{ 1 };
//    vector<int> index{ 0 };
//    obj.createTargetArray(nums, index);
//}