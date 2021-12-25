#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    void permutation(vector<int>& nums, vector<int>& permutTillNow, vector<vector<int>>& ans)
    {
        if (nums.size() == 0)
        {
            ans.push_back(permutTillNow);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            permutTillNow.push_back(temp);
            nums.erase(nums.begin() + i);
            permutation(nums, permutTillNow, ans);
            nums.insert(nums.begin()+i, temp);
            permutTillNow.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> permutTillNow;
        vector<vector<int>> ans;
        permutation(nums, permutTillNow, ans);
        return ans;
    }
};

//int main(void)
//{
//    vector<int> nums = { 6, 2, -1, 8 };
//    Solution obj;
//    obj.permute(nums);
//}
