#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    int maxPathSumUtil(TreeNode* root, int& ans)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftSubtreeSum = maxPathSumUtil(root->left, ans);
        int rightSubtreeSum = maxPathSumUtil(root->right, ans);
        int pathSumTillNow = leftSubtreeSum + rightSubtreeSum + root->val;
        ans = max(pathSumTillNow, ans);
        return max(0, root->val + max(leftSubtreeSum, rightSubtreeSum));
    }
    int maxPathSum(TreeNode* root)
    {
        int ans = INT_MIN;
        maxPathSumUtil(root, ans);
        return ans;
    }
};

//int main(void)
//{
//    int arr[] = { 1,-2,-3,1,3,-2,INT_MIN,-1 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.maxPathSum(root);
//}