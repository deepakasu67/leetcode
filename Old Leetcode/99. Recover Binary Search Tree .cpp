#include<iostream>
#include "CreateATreeWithArray.h"
class Solution {
public:
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = nullptr;

    void checkSortedness(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }

        checkSortedness(root->left);
        if(prev == NULL)
            prev = root;
        else
        {
            if(first==NULL && prev->val >= root->val)   first=prev;
            if(first!=NULL && prev->val >= root->val)   second=root;
        }

        prev = root;
        checkSortedness(root->right);

    }

    void recoverTree(TreeNode* root)
    {
        checkSortedness(root);
        swap(first->val, second->val);
    }
};
//int main(void)
//{
//    int arr[] = {3,1,4,INT_MIN,INT_MIN,2};
////    int arr[] = {4,2,6,1,3,5,7};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    inOrder(root);
//    cout<<endl;
//    Solution().checkSortedness(root);
//    inOrder(root);
//    cout<<"deepak";
//}