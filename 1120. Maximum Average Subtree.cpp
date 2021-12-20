#include<iostream>
#include<algorithm>
#include"CreateATreeWithArray.h"

using namespace std;

class Solution {
public:
    pair<int, int> averageOfEachSubtree(TreeNode* root, double& ans)
    {
        if (root == nullptr)
        {
            return { 0,0 };//sum,# of nodes
        }
        auto leftSubtreeSumAndNodes = averageOfEachSubtree(root->left, ans);
        auto rightSubtreeSumAndNodes = averageOfEachSubtree(root->right, ans);
        int sum = (root->val + leftSubtreeSumAndNodes.first + rightSubtreeSumAndNodes.first);
        int numOfNodes = (1 + leftSubtreeSumAndNodes.second + rightSubtreeSumAndNodes.second);
        ans = max(ans, (double)sum / (double)numOfNodes);
        return { sum,numOfNodes };
    }
    double maximumAverageSubtree(TreeNode* root) 
    {
        double ans = 0;
        averageOfEachSubtree(root, ans);
        return ans;
    }
};

//int main(void)
//{
//    int arr[] = { 5,6,1,1,1,1,1 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    obj.maximumAverageSubtree(root);
//}