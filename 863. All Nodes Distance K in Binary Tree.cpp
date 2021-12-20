#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
    void createAGraph(unordered_map<int, vector<int>>& adjList, TreeNode* root)
    {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
        {
            adjList[root->val].push_back(root->left->val);
            adjList[root->left->val].push_back(root->val);
        }
        if (root->right != nullptr)
        {
            adjList[root->val].push_back(root->right->val);
            adjList[root->right->val].push_back(root->val);
        }
        createAGraph(adjList, root->left);
        createAGraph(adjList, root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        unordered_map<int, vector<int>> adjList;
        createAGraph(adjList, root);
        
        vector<int> result;

        queue<int> q;
        q.push(target->val);
        unordered_set<int> visited; visited.insert(target->val);
        while (!q.empty() && K)
        {
            int size = q.size();
            while (size--)
            {
                int root = q.front();
                q.pop();
                for (auto it = adjList[root].begin(); it != adjList[root].end(); it++)
                {
                    if (visited.find(*it) == visited.end())
                    {
                        q.push(*it);
                        visited.insert(*it);
                    }
                }
            }
            K--;
        }
        
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};

//int main(void)
//{
//    int arr[] = { 3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    Solution obj;
//    obj.distanceK(root, root->left, 2);
//}