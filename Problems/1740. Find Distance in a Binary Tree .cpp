//
// Created by Deepak Sahu on 12/29/21.
//

#include <iostream>
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
    int findDistanceFromLCA(TreeNode* root, int node, int dist)
    {
        if(root == nullptr)
            return 0;
        if(root->val == node)
            return dist;

        int left= findDistanceFromLCA(root->left, node, dist+1);
        int right = findDistanceFromLCA(root->right, node, dist+1);
        return max(left, right);
    }
    int findDistance(TreeNode* root, int p, int q) {

        TreeNode* lca = lowestCommonAncestor(root, p, q);
        int lcaToP = findDistanceFromLCA(lca,p,0);
        int lcaToQ = findDistanceFromLCA(lca,q,0);
        return lcaToP + lcaToQ;
    }
};

//int main(void)
//{
//    int arr[] = {3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4};
//    //int arr[] = {3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4};
//    int n = sizeof(arr)/sizeof (arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    cout<<Solution().findDistance(root,5,5);
//}