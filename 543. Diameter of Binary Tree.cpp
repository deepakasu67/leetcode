#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    int diameterOfBinaryTreeUtil(TreeNode* root, int &ans)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int leftSubTreeHeight = diameterOfBinaryTreeUtil(root->left, ans);
        int rightSubTreeHeight = diameterOfBinaryTreeUtil(root->right, ans);

        ans = max(ans, leftSubTreeHeight + rightSubTreeHeight);
        return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans = 0;
        diameterOfBinaryTreeUtil(root, ans);
        return ans;
    }
};

//int main(void)
//{
//    int arr[] = { 1,2,3,4,5 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.diameterOfBinaryTree(root);
//}