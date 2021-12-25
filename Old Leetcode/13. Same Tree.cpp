#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p == nullptr && q == nullptr)
        {
            return true;
        }
        if(p == nullptr || q == nullptr)
        {
            return false;
        }
        if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        {
            return true;
        }
        else
            return false;
    }

};

//int main(void)
//{
//    int a[] = {1,2, 1};
//    int b[] = { 1, 1, 2 };
//    TreeNode* tree1 = build_tree(a, 3);
//    TreeNode* tree2 = build_tree(b, 3);
//    Solution obj;
//    cout << obj.isSameTree(tree1, tree2);
//
//}