//
// Created by Deepak Sahu on 1/7/22.
//
#include <iostream>
#include <utility>
#include <vector>
#include "CreateATreeWithArray.h"
using namespace std;


class Solution {
public:
    vector<int> largestBSTSubtreeUtil(TreeNode* root, int &maxiSum)
    {
        vector<int> result;
        if (root == nullptr)
            return result = { true, 0, INT_MIN, INT_MAX }; // isBST, # of nodes, max num, min_num
        vector<int> largestLeftBST= largestBSTSubtreeUtil(root->left, maxiSum);
        vector<int> largestRightBST = largestBSTSubtreeUtil(root->right, maxiSum);

        if(largestLeftBST[0] == true && largestRightBST[0] == true)
        {
            if(root->val > largestLeftBST[2] && root->val < largestRightBST[3])
            {
                maxiSum = max(maxiSum,largestLeftBST[1] + largestRightBST[1] + root->val);
                return result  = { true,
                                   largestLeftBST[1] + largestRightBST[1] + root->val,
                                   max(max(largestLeftBST[2], largestRightBST[2]),root->val),
                                   min(min(largestLeftBST[3], largestRightBST[3]), root->val) };
            }
        }
        return { false, max(largestLeftBST[1], largestRightBST[1]) , INT_MIN, INT_MAX };
    }
    int maxSumBST(TreeNode* root)
    {
        int maxSum = 0;
        largestBSTSubtreeUtil(root, maxSum);
        return maxSum;
    }
};

//int main(void)
//{
//    int arr[] ={1,4,3,2,4,2,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,6};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    TreeNode* root = build_tree(arr,n);
//    cout<<Solution().maxSumBST(root);
//}