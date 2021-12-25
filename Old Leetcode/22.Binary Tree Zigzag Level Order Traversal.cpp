#include<iostream>
#include <vector>
#include<algorithm>
#include <list>
#include<queue>
#include "CreateATreeWithArray.h"
using namespace std;
class Solution {
    int level = 0;
public:
    void zigzagLevelOrderUtil(TreeNode* root, vector<list<int>>& result, int level)
    {
        if (root == nullptr)
        {
            return;
        }
        this->level = max(this->level, level);
        if (level % 2 == 0)
            result[level].push_back(root->val);
        else
            result[level].push_front(root->val);
        zigzagLevelOrderUtil(root->left, result, level + 1);
        zigzagLevelOrderUtil(root->right, result, level + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<list<int>> resultWithList(10000, list<int>());
        zigzagLevelOrderUtil(root, resultWithList, 0);
        resultWithList.resize(level + 1);

        vector<vector<int>> result;

        for_each(resultWithList.begin(), resultWithList.end(), [&result](list<int> nodes)
            {
                result.push_back({ nodes.begin(), nodes.end() });
            });
        return result;
    }
};