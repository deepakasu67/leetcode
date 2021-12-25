#include<iostream>
#include<vector>
#include "CreateATreeWithArray.h"

using namespace std;
class Solution {
public:
    int search(vector<int>& inorder, int strt, int end, int value)
    {
        int i;
        for (i = strt; i <= end; i++) {
            if (inorder[i] == value)
                break;
        }
        return i;
    }
    TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int& pEnd)
    {
        if (instart > inend)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[pEnd--]);
        if (instart == inend)
        {
            return root;
        }
        int idx = search(inorder, instart, inend, root->val);
        root->right = buildTreeUtil(inorder, postorder, idx + 1, inend, pEnd);
        root->left = buildTreeUtil(inorder, postorder, instart, idx - 1, pEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.size() == 0)return nullptr;
        int n = inorder.size() - 1;
        TreeNode* root = buildTreeUtil(inorder, postorder, 0, inorder.size() - 1, n);
        return root;
    }
}; 
//int main()
//{
//    vector<int> inorder =   { 9,3,15,20,7 };
//    vector<int> postorder = { 9,15,7,20,3 };
//    Solution obj;
//    obj.buildTree(inorder, postorder);
//}