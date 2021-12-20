#include<iostream>
#include"CreateATreeWithArray.h"
#include<vector>
using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr)
            return 0;
        int leftSubTreeSum = 0, rightSubTreeSum = 0;
        if(root->val >= low)
             leftSubTreeSum = rangeSumBST(root->left, low, high);
        if(root->val <= high)
             rightSubTreeSum = rangeSumBST(root->right, low, high);

        int totalSum = leftSubTreeSum + rightSubTreeSum + ((root->val >= low && root->val <= high) ? root->val : 0);
        return totalSum;
    }
};

//int main(void)
//{
//    int arr[] = { 10,5,15,3,7,13,18,1,INT_MIN,6 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.rangeSumBST(root, 6, 10);
//}