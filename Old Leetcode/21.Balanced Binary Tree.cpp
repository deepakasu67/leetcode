#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    int isBalancedUtil(TreeNode* root, int level)
    {
        if(root == nullptr)
        {
            return 0;
        }

        int leftSubtreeHeight = isBalancedUtil(root->left, level + 1);
        int rightSubtreeHeight = isBalancedUtil(root->right, level + 1);

        if (leftSubtreeHeight == -1 || rightSubtreeHeight == -1)
            return -1;

        int heightDiff = abs(leftSubtreeHeight - rightSubtreeHeight);
        if(heightDiff >= 2)
        {
            return -1;
        }
        return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
    }
    bool isBalanced(TreeNode* root)
    {
        if (isBalancedUtil(root, 0) == -1)
            return false;
        else
            return true;
    }
};

//int main(void)
//{
//    int arr[] = { 1,2,2,3,3,INT_MIN,INT_MIN,4,4 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    Solution obj;
//    TreeNode* root = build_tree(arr, n);
//    obj.isBalanced(root);
//}