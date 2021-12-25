#include<iostream>
#include<utility>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    pair<pair<int, int>, int> maxAncestorDiffFromTopRoot(TreeNode* root)
    {
        if (root == nullptr)
        {
            return make_pair(make_pair(0, INT_MAX), 0);
        }
        auto leftMaxMinMaxAncestorDiff = maxAncestorDiffFromTopRoot(root->left);
        auto rightMaxMinAncestorDiff = maxAncestorDiffFromTopRoot(root->right);

        int Min = min(root->val, min(leftMaxMinMaxAncestorDiff.first.second, rightMaxMinAncestorDiff.first.second));
        int Max = max(root->val, max(leftMaxMinMaxAncestorDiff.first.first, rightMaxMinAncestorDiff.first.first));
        int maxRootChildDiff = max(abs(root->val - Min), abs(root->val - Max));
        int maxAncDiff = max(maxRootChildDiff, max(leftMaxMinMaxAncestorDiff.second, rightMaxMinAncestorDiff.second));
        return make_pair(make_pair(Max, Min), maxAncDiff);
    }
    int maxAncestorDiff(TreeNode* root)
    {
        int maxEle = 0, minEle = INT_MAX;
        auto maxAncestorDiff = maxAncestorDiffFromTopRoot(root);
        return maxAncestorDiff.second;
    }
};
//int main(void)
//{
//    //int arr[] = { 2,4,3,1,INT_MIN,0,5,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,7 };
//    int arr[] = { 8,3,10,1,6,INT_MIN,14,INT_MIN,INT_MIN,4,7,13 };
//    //int arr[] = { 1,INT_MIN,2,INT_MIN,0,3 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    Solution obj;
//    TreeNode* root = build_tree(arr, n);
//    cout<<obj.maxAncestorDiff(root);
//}