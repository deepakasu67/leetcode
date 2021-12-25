#include<iostream>
#include <string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void pathSum(string& root , unordered_map<string, int>& tree, int &ans, int sum)
    {
        int x = root[0] -'0';
        int y = root[1] -'0';

        string left = to_string(x + 1) + to_string(y*2 - 1);
        string right = to_string(x + 1) + to_string(y * 2);

        if(tree.count(left) == 0 && tree.count(right) == 0) 
        {
            ans += (sum + tree[root]);
            return;
        }

        if(tree.count(left))
            pathSum(left, tree, ans, sum + tree[root]);
        if(tree.count(right))
            pathSum(right, tree, ans, sum + tree[root]);

    }
    int pathSum(vector<int>& nums)
    {
        unordered_map<string, int> tree;
        for(int num : nums)
        {
            string s = to_string(num);
            string key = s.substr(0, 2);
            int v = s[2] - '0';
            tree[key] = v;
        }
        int ans = 0;
        string root = "11";
        pathSum(root, tree, ans, 0);
        return ans;
    }
};
//
//int main(void)
//{
//    vector<int> inp = { 113, 221 };
//    Solution obj;
//    obj.pathSum(inp);
//}