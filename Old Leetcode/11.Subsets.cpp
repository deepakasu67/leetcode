#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(vector<int>{nums[i]});
            int size = result.size() - 1;
            for (int j = 1; j < size; j++)
            {
                vector<int> temp = result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = { 1,2,3 };
//    Solution obj;
//    obj.subsets(nums);
//}