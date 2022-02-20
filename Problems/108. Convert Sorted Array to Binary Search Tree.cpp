//
// Created by Deepak Sahu on 12/24/21.
//
#include <iostream>
#include<vector>
#include "CreateATreeWithArray.h"
#include <cmath>
using namespace  std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r)
    {
        if(l > r)
            return nullptr;

        int mid = l + ceil(((double)r - l)/2);

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBST(nums, l, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, r);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBST(nums,0, nums.size() - 1 );
    }
};
//
//int main(void)
//{
//    vector<int> arr = {-10,-3,0,5,9};
//    TreeNode* root = (Solution().sortedArrayToBST(arr));
//    inOrder(root);
//}
