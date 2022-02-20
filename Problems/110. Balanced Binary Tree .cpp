//
// Created by Deepak Sahu on 2/4/22.
//

#include <iostream>
#include "CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    const pair<int, bool>& isBalancedUtil(TreeNode* root)
    {
        if(root == nullptr)
            return {0,true};

        auto leftSubtreeHeight = isBalancedUtil(root->left);
        auto rightSubtreeHeight = isBalancedUtil(root->right);
        if(leftSubtreeHeight.second == true && rightSubtreeHeight.second == true)
        {
            if(abs(leftSubtreeHeight.first - rightSubtreeHeight.first) <= 1)
                return {1+ max(leftSubtreeHeight.first, rightSubtreeHeight.first), true};
        }
        return {1+ max(leftSubtreeHeight.first, rightSubtreeHeight.first), false};
    }
    bool isBalanced(TreeNode* root) {

        auto isBalance = isBalancedUtil(root).second;
        return isBalance;
    }
};

//int main(void)
//{
//    int arr[] = {1,2,2,3,3,INT_MIN,INT_MIN,4,4};
//    int n = sizeof (arr)/sizeof (arr[0]);
//    TreeNode* root = build_tree(arr,n);
//    Solution().isBalanced(root);
//}
