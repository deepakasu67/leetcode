#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include "CreateATreeWithArray.h"
using namespace  std;
class Solution {
public:
	void levelOrderBottomUtil(TreeNode* root, map<int, vector<int>>&result, int level)
	{
		if(root == nullptr)
		{
            return;
		}
        if (result.find(level) == result.end())
            result[level] = vector<int>();
        levelOrderBottomUtil(root->left, result, level + 1);
        levelOrderBottomUtil(root->right, result, level + 1);        
        result[level].emplace_back(root->val);
	}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        map<int ,vector<int>> result;
        levelOrderBottomUtil(root, result, 0);
        //return { result.begin(), result.end() };
        vector<vector<int>> resultBottomUp;
        for_each(result.rbegin(), result.rend(), [&resultBottomUp](auto &levelsElm)
            {
                resultBottomUp.push_back(levelsElm.second);
            });
        return resultBottomUp;
    }
};

//int main(void)
//{
//    Solution obj;
//    int a[] = { 3,9,20,INT_MIN,INT_MIN,15,7 };
//    int n = sizeof(a) / sizeof(int);
//    TreeNode* root = build_tree(a, n);
//    inOrder(root);
//    obj.levelOrderBottom(root);
//}