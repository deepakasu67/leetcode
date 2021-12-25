#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;
        if (root->val == val)
        {
            return root;
        }
        TreeNode* leftSubtree = searchBST(root->left, val);
        TreeNode* rightSubtree = searchBST(root->right, val);
        if (leftSubtree != nullptr)
            return leftSubtree;
        else
            return rightSubtree;
    }
};

//int main(void)
//{
//    int a[] = {};
//    TreeNode* root = build_tree(a,0);
//
//    inOrder(root);
//    Solution obj;
//
//    root = obj.searchBST(root, 2);
//    cout << endl;
//    inOrder(root);
//}