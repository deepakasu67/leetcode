#include<iostream>
#include"CreateATreeWithArray.h"
#define MOD 1000000007
using namespace std;

class Solution {
public:
    int sumOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int leftSubtreeSum = sumOfBinaryTree(root->left);
        int rightSubtreeSum = sumOfBinaryTree(root->right);
        return root->val+ leftSubtreeSum + rightSubtreeSum;
    }
    int maxProductByBreakingIntoTwoPart(TreeNode* root, int sumOfTree, long int &maxProduct, int sumTillNow)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftSubtreeSum = maxProductByBreakingIntoTwoPart(root->left, sumOfTree, maxProduct, sumTillNow);
        int rightSubtreeSum = maxProductByBreakingIntoTwoPart(root->right, sumOfTree, maxProduct, sumTillNow);

        int currentSubtreeSum = leftSubtreeSum + rightSubtreeSum + root->val;
        long int subtreeWithoutCurrentSubtree = sumOfTree - currentSubtreeSum;
        maxProduct = max(maxProduct, ((subtreeWithoutCurrentSubtree %MOD) * (currentSubtreeSum %MOD)));
        return currentSubtreeSum;
    }

    int maxProduct(TreeNode* root) 
    {
        int sumOfTree = sumOfBinaryTree(root);
        long int maxProduct = 0;
        maxProductByBreakingIntoTwoPart(root, sumOfTree, maxProduct, 0);
        return maxProduct%MOD;
    }
};

//int main(void)
//{
//    int arr[] = { 1,2,3,4,5,6 };
//    int n = sizeof(arr) / sizeof(n);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.maxProduct(root);
//    
//}