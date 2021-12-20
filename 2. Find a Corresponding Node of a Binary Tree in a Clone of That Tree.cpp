#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;
class Solution {
public:
    //can't handle duplicates
    //TreeNode* getTargetCopyUtil(TreeNode* cloned, TreeNode* target)
    //{
    //    if (cloned == nullptr)
    //    {
    //        return nullptr;
    //    }
    //    if (target->val == cloned->val)
    //    {
    //        return cloned;
    //    }
    //    TreeNode* leftSubtree = getTargetCopyUtil(cloned->left, target);
    //    TreeNode* rightSubtree = getTargetCopyUtil(cloned->right, target);
    //    if (leftSubtree != nullptr)
    //    {
    //        return leftSubtree;
    //    }
    //    else
    //    {
    //        return rightSubtree;
    //    }
    //}
    void getVerticalDistance(TreeNode* Original, TreeNode* target, int level, int vd, pair<int, int>& lvl_VD)
    {
        if(Original == nullptr)
        {
            return;
        }
        if(target == Original)
        {
            lvl_VD = make_pair(level, vd);
            return;
        }
        getVerticalDistance(Original->left, target, level + 1, vd - 1, lvl_VD);
        getVerticalDistance(Original->right, target, level + 1, vd + 1, lvl_VD);
    }
    TreeNode* findTargetInClonedTree(TreeNode* cloned, TreeNode* target, int level, int vd,pair<int, int>& lvl_VD)
    {
        if(cloned == nullptr)
        {
            return nullptr;
        }
        if(cloned->val == target->val && 
            level == lvl_VD.first && 
            vd == lvl_VD.second)
        {
            return cloned;
        }
        TreeNode* leftSubtree = findTargetInClonedTree(cloned->left, target,level + 1, vd - 1, lvl_VD);
        TreeNode* rightSubtree = findTargetInClonedTree(cloned->right, target, level + 1, vd + 1, lvl_VD);

        return leftSubtree == nullptr ? rightSubtree == nullptr ? nullptr : rightSubtree : leftSubtree;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        pair<int, int> XandYaxis;
        getVerticalDistance(original, target, 0, 0, XandYaxis);
        return findTargetInClonedTree(cloned, target, 0, 0, XandYaxis); 
    }
};
//
//int main(void)
//{
//    int arr[] = { 1,2,3,5,5,5,5,8,9,10 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    TreeNode* root1 = build_tree(arr, n);
//    TreeNode* target = root->left->right;
//    Solution obj;
//    cout<< obj.getTargetCopy(root, root1, target)->val;
//}