#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& inorder)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    TreeNode* balanceBST(vector<int>& inorder, int low, int high)
    {
        if (low > high)
            return nullptr;

        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = balanceBST(inorder, low, mid - 1);
        root->right = balanceBST(inorder, mid + 1, high);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        TreeNode* newRoot =  balanceBST(inorder, 0, inorder.size() - 1);
        return newRoot;
    }
};

//int main(void)
//{
//    int arr[] = { 1,INT_MIN,2,INT_MIN,3,INT_MIN,4,INT_MIN,INT_MIN };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    obj.balanceBST(root);
//}