#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
    int idx = 0;
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int i, int j)
    {
        if (i > j || idx >= preorder.size())
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx++]);
        int rootIdxInorder = find(inorder.begin() + i, inorder.begin() + j, root->val) - inorder.begin();
        root->left = buildTreeHelper(preorder, inorder, i, rootIdxInorder - 1);
        root->right = buildTreeHelper(preorder, inorder, rootIdxInorder + 1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return buildTreeHelper(preorder, inorder, 0, inorder.size());
    }
};

//int main(void)
//{
//    vector<int> preorder = { 3,9,20,15,7 };
//    vector<int> inorder = { 9,3,15,20,7 };
//    TreeNode* root = Solution().buildTree(preorder, inorder);
//}