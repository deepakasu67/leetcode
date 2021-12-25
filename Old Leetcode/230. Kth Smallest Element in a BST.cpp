#include<iostream>
#include"CreateATreeWithArray.h"
#include<vector>
using namespace std;

class Solution {
public:
    TreeNode* kthSmallestUtil(TreeNode* root, int &k)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode* leftSubtree = kthSmallestUtil(root->left, k);
        k--;
        if(k == 0)
        {
            return root;
        }
        TreeNode* rightSubtree = kthSmallestUtil(root->right, k);

        return leftSubtree ? leftSubtree : rightSubtree;
    }
    int kthSmallest(TreeNode* root, int k)
    {
        TreeNode* kthSmallestNode = kthSmallestUtil(root, k);
        return kthSmallestNode->val;
    }
};

//int main(void)
//{
//    int arr[] = { 5,3,6,2,4,INT_MIN,INT_MIN,1 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    obj.kthSmallest(root, 3);
//}