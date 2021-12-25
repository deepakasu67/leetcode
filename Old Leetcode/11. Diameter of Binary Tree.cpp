#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root, int& maxi)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftSubtreeMax = diameterOfBinaryTree(root->left, maxi);
        int rightSubtreeMax = diameterOfBinaryTree(root->right, maxi);

        int crossThisNodeSize =  1 + leftSubtreeMax + rightSubtreeMax;
        maxi = max(max(maxi,crossThisNodeSize), max(leftSubtreeMax, rightSubtreeMax));
        return max(leftSubtreeMax, rightSubtreeMax) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxi = 0;
        diameterOfBinaryTree(root, maxi);
        return maxi - 1;
    }
};

//int main(void)
//{
//    int arr[] = { 4,-7,-3,INT_MIN,INT_MIN,-9,-3,9,-7,-4,INT_MIN,6,INT_MIN,-6,-6,INT_MIN,INT_MIN,0,6,5,INT_MIN,9,INT_MIN,INT_MIN,-1,-4,INT_MIN,INT_MIN,INT_MIN,-2 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    Solution obj;
//    TreeNode* root = build_tree(arr, n);
//    obj.diameterOfBinaryTree(root);
//}