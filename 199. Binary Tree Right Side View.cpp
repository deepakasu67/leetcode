#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    void rightSideView(TreeNode* root, int level, vector<int> &result)
    {
        if (root == nullptr)
            return;
        if(result.size() <= level)
        {
            result.push_back(root->val);
        }
        else
        {
            result[level] = root->val;
        }
        rightSideView(root->left, level + 1, result);
        rightSideView(root->right, level + 1, result);
    }
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> result;
        rightSideView(root, 0, result);
        return result;
    }
};

//int main(void)
//{
//    Solution obj;
//    int arr[] = { 1,2,3,INT_MIN,5,INT_MIN,4 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    obj.rightSideView(root);
//}
