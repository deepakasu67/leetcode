#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ( p == nullptr && q == nullptr )
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        }
    }
};
//int main(void)
//{
//    int a[] = { 1,2};
//    int b[] = { 1,INT_MIN,2};
//    TreeNode* root1 = build_tree(a, 3);
//    TreeNode* root2 = build_tree(b, 3);
//    Solution obj;
//    cout<<obj.isSameTree(root1, root2);
//}