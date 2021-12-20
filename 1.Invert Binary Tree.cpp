#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;
        root->left = rightSubtree;
        root->right = leftSubtree;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
//int main(void)
//{
//    int a[] = {4, 2, 7, 1, 3, 6, 9};
//    TreeNode *root = build_tree(a, 7);
//    Solution obj;
//    root = obj.invertTree(root);
//}