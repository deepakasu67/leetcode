#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
#include<unordered_map>
using namespace std;

class Solution {
public:
    int robHelper(TreeNode* root, unordered_map<TreeNode*, int>& dp)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (dp.find(root) != dp.end())
        {
            return dp[root];
        }
        //robbing
        int rob = 0;
        if (root->left != nullptr)
        {
            rob += robHelper(root->left->left, dp);
            rob += robHelper(root->left->right, dp);
        }
        if (root->right != nullptr)
        {
            rob += robHelper(root->right->left, dp);
            rob += robHelper(root->right->right, dp);
        }
        //not Robbing
        int notRob = 0;
        notRob += robHelper(root->left, dp);
        notRob += robHelper(root->right, dp);
        
        dp[root] = max(rob + root->val, notRob);
        return dp[root];
    }
    int rob(TreeNode* root)
    {
        unordered_map<TreeNode*, int> dp;
        return robHelper(root, dp);
    }
};

//int main(void)
//{
//    int arr[] = { 2,1,3,INT_MIN,4 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.rob(root);
//}