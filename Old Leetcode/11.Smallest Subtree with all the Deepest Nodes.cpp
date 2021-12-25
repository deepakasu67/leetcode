#include<iostream>
#include<algorithm>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    void deepestNodeAtTheEnd(TreeNode* root, TreeNode* &leftEnd, TreeNode* &rightEnd, int height, int level)
    {
        if (root == nullptr)
            return;
        if (height == level)
        {
            if (leftEnd == nullptr)
            {
                leftEnd = root;
            }
            else
                rightEnd = root;
        }
        deepestNodeAtTheEnd(root->left, leftEnd, rightEnd, height, level + 1);
        deepestNodeAtTheEnd(root->right, leftEnd, rightEnd, height, level + 1);
    }
    int heightOfTree(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
    }
    TreeNode* LCAOfTwoDeepestNode(TreeNode* root, int leftEndNode, int rightEndNode)
    {
        if (root == nullptr)
            return nullptr;

        if(root->val == leftEndNode || root->val == rightEndNode)
        {
            return root;
        }

        TreeNode* lcafromLeftSubtree = LCAOfTwoDeepestNode(root->left, leftEndNode, rightEndNode);
        TreeNode* lcaFromRightSubtree = LCAOfTwoDeepestNode(root->right, leftEndNode, rightEndNode);
        if (lcafromLeftSubtree && lcaFromRightSubtree)
            return root;
        return lcaFromRightSubtree == nullptr ? lcafromLeftSubtree : lcaFromRightSubtree;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        int hieghtOfTree = heightOfTree(root);
        TreeNode* leftEnd = nullptr;
        TreeNode* rightEnd = nullptr;
        deepestNodeAtTheEnd(root, leftEnd, rightEnd, hieghtOfTree, 1);
        if(leftEnd != nullptr && rightEnd != nullptr)
        {
            TreeNode* rootSubtree = LCAOfTwoDeepestNode(root, leftEnd->val, rightEnd->val);
            return rootSubtree;
        }
        return leftEnd == nullptr ? rightEnd : leftEnd;
    }
};

//int main(void)
//{
//    int arr[] = { 3,5,1,6,2,0,8,78,INT_MIN,INT_MIN,INT_MIN,INT_MIN,89,INT_MIN,34 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    Solution obj;
//    TreeNode* root = build_tree(arr,n);
//    obj.subtreeWithAllDeepest(root);
//}