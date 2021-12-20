#include<iostream>
#include<vector>
#include "CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int>& inorder)
    {
        if(root == nullptr)
        {
            return;
        }
        inOrderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inOrderTraversal(root->right, inorder);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        vector<int> inOrder;
        inOrderTraversal(root, inOrder);
        TreeNode* result = new TreeNode(inOrder[0]);
        TreeNode* newRoot = result;
        for(int i = 1 ;i < inOrder.size();i++)
        {
            result->right = new TreeNode(inOrder[i]);
            result = result->right;
        }
        return newRoot;
    }
};
//int main(void)
//{
//    int arr[] = { 5,3,6,2,4,INT_MIN,8,1,INT_MIN,INT_MIN,INT_MIN,7,9};
//    int size = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, size);
//    Solution obj;
//    TreeNode* newRoot = obj.increasingBST(root);
//}