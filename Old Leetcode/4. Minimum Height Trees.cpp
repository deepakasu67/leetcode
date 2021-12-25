#include<iostream>
#include<vector>
#include<queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n == 1)
            return { 0 };
        vector<std::unordered_set<int>> adjList(n);
        for(int i = 0 ;i < edges.size(); i++)
        {
            adjList[edges[i][0]].insert(edges[i][1]);
            adjList[edges[i][1]].insert(edges[i][0]);
        }
        queue<int> q;
        for(int i = 0; i < adjList.size(); i++)
        {
            if(adjList[i].size() == 1)
            {
                q.push(i);
            }
        }
        while(n > 2)
        {
            int numberOfLeaf = q.size();
            n = n - numberOfLeaf;
            for(int i = 0;i < numberOfLeaf; i++)
            {
                int node = q.front();
                q.pop();
                
                for(auto& a : adjList[node])
                {
                    adjList[a].erase(node);
                    if(adjList[a].size() == 1)
                    {
                        q.push(a);
                    }
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
//int main(void)
//{
//    vector<vector<int>> edges = { {3, 0},{3, 1},{3, 2},{3, 4},{5, 4} };
//
//    Solution obj;
//    vector<int> result;
//    result = obj.findMinHeightTrees(6, edges);
//}
