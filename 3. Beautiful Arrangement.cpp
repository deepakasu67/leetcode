#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countArrangementUtil(vector<int>& nums, int n, vector<bool> &visited)
    {
        if (n == nums.size())
        {
            return 1;
        }
        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i-1] == false)
            {
                if ((i % (nums.size() + 1) == 0) || (nums.size() + 1) % i == 0)
                {
                    visited[i - 1] = true;
                    nums.push_back(i);
                    total += countArrangementUtil(nums, n, visited);
                    visited[i - 1] = false;
                    nums.pop_back();
                }
            }
        }
        return total;
    }
    int countArrangement(int n) 
    {
        vector<int> nums;
        vector<bool> visited(n, false);
        return countArrangementUtil(nums, n, visited);
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.countArrangement(3);
//}