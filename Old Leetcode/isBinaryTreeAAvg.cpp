#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;
bool isLeaf(TreeNode* root)
{
    return (root->left == nullptr) && (root->right == nullptr);
}
pair<int,pair<int,bool>> isAverageTreeUtil(TreeNode* root)
{
    if(root == nullptr)
    {
        return make_pair(0,make_pair(0,true));
    }
    pair<int, pair<int, bool>> leftSubtree = isAverageTreeUtil(root->left);
    pair<int, pair<int, bool>> rightSubtree = isAverageTreeUtil(root->right);

    if (isLeaf(root))
    {
        return make_pair(root->val, make_pair(1, true));
    }

    int totalSum = leftSubtree.first + rightSubtree.first;
    int numOfNodes = leftSubtree.second.first + rightSubtree.second.first;
    int avg = 0;
    if(numOfNodes > 0)
        avg = float(totalSum) / (float)(numOfNodes);


    totalSum += root->val;
    numOfNodes++;

    if(avg == root->val)
    {
        return make_pair(totalSum, make_pair(numOfNodes, leftSubtree.second.second && rightSubtree.second.second));
    }
    else
    {
        return make_pair(totalSum, make_pair(numOfNodes, false));
    }
}

bool isTreeAvgTree(TreeNode* root)
{
    auto result = isAverageTreeUtil(root);
    return result.second.second;
}

//int main(void)
//{
//    int arr[] = { 9,7,12,6,8,9,15 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    isTreeAvgTree(root);
//}