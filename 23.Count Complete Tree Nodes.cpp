#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
//int main(void)
//{
//    int a[] = { 1,2,3,4,5,6 };
//    Solution obj;
//    TreeNode* root = build_tree(a, 6);
//    cout<<obj.countNodes(root);
//}