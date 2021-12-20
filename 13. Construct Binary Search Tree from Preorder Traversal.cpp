#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;
class Solution {
public:
    //TreeNode* bstFromPreoreder(vector<int>& preorder, int subtreeStart, int subtreeEnd)
    //{
    //    if (subtreeStart > subtreeEnd)
    //        return nullptr;

    //    TreeNode* root = new TreeNode(preorder[subtreeStart]);
    //    int i = 0;
    //    for (i = subtreeStart+ 1; i <= subtreeEnd; i++)
    //    {
    //        if (preorder[subtreeStart] <= preorder[i])
    //            break;
    //    }
    //    root->left = bstFromPreoreder(preorder, subtreeStart + 1, i - 1);
    //    root->right= bstFromPreoreder(preorder, i, subtreeEnd);
    //    return root;
    //}

    TreeNode* bstFromPreOrder(vector<int>& preorder,int &idx ,int minV, int maxV)
    {
        if (idx > preorder.size() - 1)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[idx]);

        if (root->val > maxV || root->val < minV)
            return nullptr;
        idx++;
        root->left = bstFromPreOrder(preorder, idx, minV, root->val - 1);
        root->right = bstFromPreOrder(preorder, idx, root->val + 1, maxV);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int idx = 0;
        return bstFromPreOrder(preorder, idx, INT_MIN, INT_MAX);
    }
};

//int main(void)
//{
//    vector<int> nums = { 8,5,1,7,10,12 };
//    Solution obj;
//    TreeNode* root = obj.bstFromPreorder(nums);
//}