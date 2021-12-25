#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    int findTiltUtil(TreeNode* root, int &tilt)
    {
        if (root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }
        int leftVal  = findTiltUtil(root->left, tilt);
        int rightVal = findTiltUtil(root->right, tilt);
        tilt += abs(leftVal - rightVal);
        return leftVal + rightVal + root->val;
    }
    int findTilt(TreeNode* root)
    {
        int tilt = 0;
        findTiltUtil(root, tilt);
        return tilt;
    }
};
//int main(void)
//{
//    int arr[] = { 4,2,9,3,5,INT_MIN,7 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    obj.findTilt(root);
//}