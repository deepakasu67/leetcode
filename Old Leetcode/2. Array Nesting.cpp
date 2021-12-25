#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int traverseAllTheReachableNode(vector<int>& nums, vector<int>& countOfChain, int current)
    {
        if (countOfChain[current] > 0)
        {
            return 0;
        }
        countOfChain[current] = 1;
        countOfChain[current] += traverseAllTheReachableNode(nums, countOfChain, nums[current]);
        return countOfChain[current];
    }
    int arrayNesting(vector<int>& nums) 
    {
        vector<int> countOfChain(nums.size(), 0);
        int maxNestedChain = 0;
        int countOfNestedChain = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (countOfChain[i] == 0)
            {
                traverseAllTheReachableNode(nums, countOfChain, i);
            }
            maxNestedChain = max(countOfChain[i], maxNestedChain);
        }
        return maxNestedChain;
    }
};

//int main(void)
//{
//    vector<int> arr = {0,1,2 };
//    Solution obj;
//    cout<<obj.arrayNesting(arr);
//} 