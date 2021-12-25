#include<iostream>
#include "CreateATreeWithArray.h"
using namespace std;
class Solution {
    int sum = 0;
public:
    void sumOfLeftLeavesUtil(TreeNode* root, bool isLeft)
    {
        if (root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
        {
            if (isLeft == true)
                sum += root->val;
            return;
        }
        sumOfLeftLeavesUtil(root->left, true);
        sumOfLeftLeavesUtil(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root)
    {
        sumOfLeftLeavesUtil(root, false);
        return sum;
    }
};
//int main(void)
//{
//    int a[] = { 3,9};
//    int siz = sizeof(a) / sizeof(int);
//    TreeNode* root = build_tree(a, siz);
//    Solution obj;
//    cout << obj.sumOfLeftLeaves(root);
//}