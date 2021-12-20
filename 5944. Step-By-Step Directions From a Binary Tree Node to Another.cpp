#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"CreateATreeWithArray.h"
#include<unordered_set>
using namespace std;

class Solution {
    TreeNode* startNode = nullptr;
    TreeNode* endNode = nullptr;
public:
    void createGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>> &graph, int start, int end)
    {
        if (root == nullptr)
            return;

        if (root->val == start)
            startNode = root;
        if (root->val == end)
            endNode = root;

        
        if (root->left)
        {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            createGraph(root->left, graph,start, end);
        }
        if (root->right)
        {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            createGraph(root->right, graph,start, end);
        }
    }
    void bfs(unordered_map<TreeNode*, vector<TreeNode*>> graph, TreeNode* root, vector<TreeNode*> &path)
    {
        queue<TreeNode*> q;
        q.push(root);
        unordered_set<TreeNode*> visited;
        visited.insert(root);
        while (!q.empty())
        {
            TreeNode* front = q.front();
            path.push_back(front);
            if (front == endNode)
                return;
            q.pop();
            for (auto it = graph[front].begin(); it != graph[front].end(); it++)
            {
                if (!visited.count(*it))
                {
                    visited.insert(*it); 
                    q.push(*it);
                }
            }
        }
    }

    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        vector<TreeNode*> path;
        createGraph(root, graph,startValue,destValue);
        bfs(graph, startNode, path);
        string ans;
        for (int i = 0; i < path.size()-1; i++)
        {
            if (path[i]->left == path[i+1])
            {
                ans += 'L';
            }
            else if (path[i + 1]->left == path[i])
            {
                ans += 'U';
            }
            else  if (path[i]->right == path[i + 1])
            {
                ans += 'R';
            }
            else if (path[i + 1]->right == path[i])
            {
                ans += 'U';
            }
                
        }
        return ans;
    }
};
//
//int main(void)
//{
//    int arr[] = { 5,1,2,3,INT_MIN,6,4 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    cout<<Solution().getDirections(root, 3, 6);;
//}