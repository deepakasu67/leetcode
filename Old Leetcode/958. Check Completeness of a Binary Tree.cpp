#include<iostream>
#include<queue>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) 
    {
        if (root == nullptr)
            return true;
        queue<TreeNode*> que;
        que.push(root);
        bool end = false;
        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if (node == nullptr)
            {
                end = true;
            }
            else
            {
                if (end == true)
                {
                    return false;
                }
                que.push(node->left);
                que.push(node->right);
            }
        }
        return true;
    }
};

//int main(void)
//{
//    int arr[] = { 1,2,3,4,5,INT_MIN,6 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.isCompleteTree(root);
//}

