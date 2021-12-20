#include"CreateATreeWithArray.h"

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original || cloned)
            return nullptr;
        if ((original->val == target->val) && (cloned->val == target->val))
        {
            return cloned;
        }
        
        TreeNode* leftSubTree = getTargetCopy(original->left, cloned->left, target);
        TreeNode* rightSubTree = getTargetCopy(original->right, cloned->right, target);
        
        return leftSubTree == nullptr ?  rightSubTree :  leftSubTree ;
    }
};

//int main()
//{
//    int arr[] = { 7,4,3,0,0,6,19 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root1 = nullptr;
//    TreeNode* root = insertLevelOrder(arr, root1, 0, n);
//    inOrder(root);
//}