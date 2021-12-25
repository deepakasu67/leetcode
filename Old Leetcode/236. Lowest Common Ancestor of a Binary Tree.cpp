#include<iostream>
#include "CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if (root == p || root == q)
            return root;

        TreeNode* leftSubtree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSubtree = lowestCommonAncestor(root->right, p, q);

        if (leftSubtree && rightSubtree)
            return root;
        return leftSubtree == nullptr ? rightSubtree : leftSubtree;
    }
};

//int main(void)
//{
//    
//}