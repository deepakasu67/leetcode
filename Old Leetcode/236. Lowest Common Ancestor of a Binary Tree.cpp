#include<iostream>
#include "CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if (root->val == p || root->val == q)
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
//    int arr[] = {3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4};
//    //int arr[] = {3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4};
//    int n = sizeof(arr)/sizeof (arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    cout<<Solution().lowestCommonAncestor(root,5,7)->val;
//}