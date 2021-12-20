#include<iostream>
#include<vector>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    vector<int> largestBSTSubtreeUtil(TreeNode* root)
    {
        vector<int> result;
        if (root == nullptr)
            return result = { true, 0, INT_MIN, INT_MAX }; // isBST, # of nodes, max num, min_num
        vector<int> largestLeftBST= largestBSTSubtreeUtil(root->left);
        vector<int> largestRightBST = largestBSTSubtreeUtil(root->right);

        if(largestLeftBST[0] == true && largestRightBST[0] == true)
        {
            if(root->val > largestLeftBST[2] && root->val < largestRightBST[3])
            {
                return result  = { true,
                    largestLeftBST[1] + largestRightBST[1] + 1,
                    max(max(largestLeftBST[2], largestRightBST[2]),root->val),
                    min(min(largestLeftBST[3], largestRightBST[3]), root->val) };
            }
        }
        return { false, max(largestLeftBST[1], largestRightBST[1]), INT_MIN, INT_MAX };
    }
    int largestBSTSubtree(TreeNode* root)
    {
        return largestBSTSubtreeUtil(root)[1];
    }
};

//int main(void)
//{
//    int arr[] = { 10,5,15,1,8,INT_MIN, 7 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    cout << obj.largestBSTSubtree(root);
//}