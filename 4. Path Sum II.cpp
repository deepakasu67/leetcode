#include<iostream>
#include<vector>
#include "CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    void pathSumEqualsTarget(
        TreeNode* root,
        vector<int>& interimResult ,
        int sum, 
        int targetSum, 
        vector<vector<int>> &result)
    {
        if(root== nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            interimResult.push_back(root->val);
            if (sum + root->val == targetSum)
            {
                result.push_back(interimResult);
            }
            interimResult.pop_back();
            return;
        }
        interimResult.push_back(root->val);
        pathSumEqualsTarget(root->left, interimResult,root->val + sum, targetSum, result);
        pathSumEqualsTarget(root->right, interimResult, root->val + sum, targetSum, result);
        interimResult.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> interimResult;
        vector<vector<int>> result;
        pathSumEqualsTarget(root, interimResult, 0, targetSum, result);
        return result;
    }
};

//int main(void)
//{
//    int arr[] = { 5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,5,1 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    obj.pathSum(root, 22);
//}