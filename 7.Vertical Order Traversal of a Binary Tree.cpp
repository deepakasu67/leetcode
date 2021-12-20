#include<iostream>
#include<map>
#include<set>
#include<vector>
#include "CreateATreeWithArray.h"
#include<algorithm>
#include <unordered_set>
using namespace std;
class Solution {
   map<int, map<int, set<int>>> vHtList;
public:
    void verticalTraversalUtil(TreeNode* root, int verticleHt, int level)
    {
        if(root == nullptr)
        {
            return;
        }
        if(vHtList.find(verticleHt) == vHtList.end())
        {
            vHtList[verticleHt].insert(make_pair(level, set<int>()));
        }
        vHtList[verticleHt][level].insert(root->val);
        verticalTraversalUtil(root->left, verticleHt - 1, level + 1);
        verticalTraversalUtil(root->right, verticleHt + 1, level + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        verticalTraversalUtil(root, 0,0);
        vector<vector<int>> result(vHtList.size());
        int i = 0;
        for(auto it = vHtList.begin();it!=vHtList.end();it++)
        {
            for(auto innerIt = it->second.begin();innerIt!=it->second.end(); innerIt++)
            {
                for(auto innerInnerIt = innerIt->second.begin();innerInnerIt != innerIt->second.end();innerInnerIt++)
                {
                    result[i].push_back(*innerInnerIt);
                }
            }
            i++;
        }

        return  result;
    }
};
//int main(void)
//{
//    int a[] = { 3,9,20,INT_MIN,INT_MIN,15,7 };
//    Solution obj;
//    TreeNode* root = build_tree(a, 7);
//    obj.verticalTraversal(root);
//}