#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include"CreateATreeWithArray.h"
#include <unordered_map>
class Solution {
public:
    void dfs(TreeNode* root, int sum, int cur, int& ans) {
        if (root) {
            cur += root->val;
            if (cur == sum) {
                ans++;
            }
            dfs(root->left, sum, cur, ans);
            dfs(root->right, sum, cur, ans);
        }
    }

    void fromNode(TreeNode* root, int sum, int& ans) {
        if (root) {
            dfs(root, sum, 0, ans);
            fromNode(root->left, sum, ans);
            fromNode(root->right, sum, ans);
        }
    }

    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        fromNode(root, sum, ans);
        return ans;
    }
};
//int main(void)
//{
//    int a[] = { -3,INT_MIN,-3 };
//    TreeNode* root = build_tree(a, 3);
//    Solution obj;
//    obj.pathSum(root, -3);
//}