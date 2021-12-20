#include<iostream>
#include"CreateATreeWithArray.h"
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
using namespace std;
class Solution {
public:
    void sumNumbersUtil(TreeNode* root, int *sum, int numFormed)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            *sum += (numFormed * 10 + root->val);
        }
        else
        {
            numFormed = numFormed * 10 + root->val;
            sumNumbersUtil(root->left, sum, numFormed);
            sumNumbersUtil(root->right, sum, numFormed);
        }
    }
    int sumNumbers(TreeNode* root) 
    {
        fastIO
        int sum = 0;
        sumNumbersUtil(root, &sum, 0);
        return sum;
    }
};
//int main(void)
//{
//    int a[] = { 4,9,0,5,1 };
//    TreeNode* root = build_tree(a, 5);
//    Solution obj;
//    obj.sumNumbers(root);
//}