#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;
class Solution {
public:
    TreeNode* generateTreesutil(int n, vector<TreeNode*> &bsts)
    {
        if (n < 1)
            return nullptr;
        TreeNode* root = nullptr;
        for (int i = 1; i <= n; i++)
        {
             root = new TreeNode(i);
            root->left = generateTreesutil(i-1, bsts);
            root->right = generateTreesutil(n - i , bsts);

            bsts.push_back(root);
        }
        return root;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*> bsts;
        generateTreesutil(n, bsts);
        return bsts;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.generateTrees(3);
//
//}