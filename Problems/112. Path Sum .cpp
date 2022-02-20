//
// Created by Deepak Sahu on 2/4/22.
//
#include <iostream>
#include "CreateATreeWithArray.h"
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum, int currSum) {
        if(root == nullptr)
        {
            return false;
        }
        if(root->left == nullptr && root->right == nullptr)
            return currSum == targetSum;
        return hasPathSum(root->left, targetSum, currSum + root->val)
                 || hasPathSum(root->right, targetSum, currSum + root->val);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum(root, targetSum, 0);
    }
};

//int main(void)
//{
//
//}
