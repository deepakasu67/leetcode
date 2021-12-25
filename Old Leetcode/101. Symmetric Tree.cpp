#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
    
public:
    bool isSymmetricUtil(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;

        return ((left->val == right->val)
                && isSymmetricUtil(left->left, right->right)
                && isSymmetricUtil(left->right, right->left));
    }
    bool isSymmetric(TreeNode* root) 
    {
        if (root == nullptr)
            return true;
        return isSymmetricUtil(root->left, root->right);
    }
};
//int main(void)
//{
//    int arr[] = { 1,2,2,INT_MIN,3,INT_MIN,3 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode *root = build_tree(arr, n);
//    cout << std::boolalpha;
//    cout<<Solution().isSymmetric(root);
//}