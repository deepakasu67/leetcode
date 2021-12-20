#include<iostream>
#include"CreateATreeWithArray.h"
#include<vector>
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }

    void bstFromPreorderUtil(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            return ;
        }
        if (val < root->val)
        {
           bstFromPreorderUtil(root->left,val);
           if (root->left == nullptr)
           {
               root->left = new TreeNode(val);
           }
           else
               return;
        }
        else
        {
            bstFromPreorderUtil(root->right,val);
            if (root->right == nullptr)
            {
                root->right = new TreeNode(val);
            }
            else
                return;
        }
        return;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty())
        {
            return nullptr;
        }
        else
        {
            TreeNode* root = new TreeNode(preorder[0]);
            for(int i = 1; i < preorder.size();i++)
                bstFromPreorderUtil(root, preorder[i]);
            return root;

        }
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<int> preOrderTraversal = { 8,5,1,7,10,12 };
//    TreeNode* root = obj.bstFromPreorder(preOrderTraversal);
//    inOrder(root);
//}