#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    int* prevVal = nullptr;
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }
        bool validBST = true;
        bool isSorted = true;
        validBST = validBST && isValidBST(root->left);
        if (prevVal == nullptr)
            prevVal = new int(root->val);
        else
        {
            isSorted = (root->val > *prevVal);
            *prevVal = root->val;
        }

        validBST = validBST && isValidBST(root->right);
        return validBST && isSorted;
    }
};
//
//int main(void)
//{
//    int arr[] = { 5,1,6,INT_MIN,INT_MIN,3,8 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.isValidBST(root);
//}