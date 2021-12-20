#include<iostream>
#include<utility>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    pair<int, int> findMaximumAvgSubTree(TreeNode* root, double& ans)
    {
        if (root == nullptr)
        {
            return pair<int,int>(0,0);
        }
        pair<int, int> leftSubtreeSumAndCount = findMaximumAvgSubTree(root->left, ans);
        pair<int, int> rightSubtreeSumAndCount = findMaximumAvgSubTree(root->right, ans);
        int sumOfThisSubtree = (leftSubtreeSumAndCount.first + root->val + rightSubtreeSumAndCount.first);
        int numOfNodeThisSubtree = leftSubtreeSumAndCount.second + 1 + rightSubtreeSumAndCount.second;
        double avgOfSubtree = (double)sumOfThisSubtree / (double)numOfNodeThisSubtree;
        ans = max(avgOfSubtree, ans);
        cout << sumOfThisSubtree << "," << numOfNodeThisSubtree<<endl;
        return pair<int, int>(sumOfThisSubtree, numOfNodeThisSubtree);
    }
    double maximumAverageSubtree(TreeNode* root) 
    {
        double ans = 0;
        findMaximumAvgSubTree(root, ans);
        return ans;
    }
};

//int main(void)
//{
//    int arr[] = { 5, INT_MIN, 1 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout<<obj.maximumAverageSubtree(root);
//}