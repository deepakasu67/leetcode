#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    int closestValue(TreeNode* root, double target)
    {
        TreeNode* foundNode = nullptr;
        double minDiff = INT_MAX;

        while(root)
        {
            if(minDiff >= abs(target - root->val))
            {
                foundNode = root;
                minDiff = abs(target - root->val);
            }
            if(target < (double)root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return foundNode ? foundNode->val : 0;
    }
};

//int main(void)
//{
//    int arr[] = { 1500000000,1400000000 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.closestValue(root, -1500000000.0);
//}
