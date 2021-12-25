#include<iostream>
#include<vector>
#include<map>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    void verticalOrder(TreeNode* root, map<int,map<int, vector<int>>>& verticalOrderedNode, int column, int row)
    {
        if (root == nullptr)
            return;

        verticalOrderedNode[column][row].push_back(root->val);
        verticalOrder(root->left, verticalOrderedNode, column - 1, row + 1);
        verticalOrder(root->right, verticalOrderedNode, column + 1, row + 1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        map<int, map<int, vector<int>>> verticalOrderedNode;
        verticalOrder(root, verticalOrderedNode, 0, 0);
        for(const auto &col : verticalOrderedNode)
        {
            vector<int> interimResult;
            for(const auto &elems : col.second)
            {
                for(const auto &elem : elems.second)
                {
                    interimResult.push_back(elem);
                }
            }
            result.push_back(interimResult);
        }
        return result;
    }
};

//int main(void)
//{
//    int arr[] = { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    obj.verticalOrder(root);
//}