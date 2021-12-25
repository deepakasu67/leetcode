#include "CreateATreeWithArray.h"
#include<iostream>
using namespace std;

class Solution {
public:
    bool isCousinsUtil(TreeNode* root, int x, int y, int level, int &levelx, TreeNode *parent)
    {
        if (root == nullptr)
            return false;
        if (root->val == x)
        {
            levelx = level;
        }
        if (root->left && root->left->val == y)
        {
            if (root != parent && levelx == level + 1)
            {
                return true;
            }
        }
        if (root->right && root->right->val == y)
        {
            if (root != parent && levelx == level + 1)
            {
                return true;
            }
        }

        return isCousinsUtil(root->left, x, y, level + 1, levelx, root) ||
               isCousinsUtil(root->right, x, y, level + 1, levelx, root);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if (root)
        {
            int level = 0, level1= 0;
            return isCousinsUtil(root, x, y, 0, level, NULL) || isCousinsUtil(root, y, x, 0, level1, NULL);
        }
        return false;
    }
};

//int main(void)
//{
//    int arr[] = { 1,2,3,,4, };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root1 = nullptr;
//    TreeNode* root = insertLevelOrder(arr, root1, 0, n);
//    inOrder(root);
//    Solution obj;
//    obj.isCousins(root, 5,4) ? cout<<"true" : cout<<"false";
//}