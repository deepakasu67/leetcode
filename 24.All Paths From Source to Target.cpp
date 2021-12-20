#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> paths;
    int pathIndex = -1;
public:
    void allPathsSourceTargetUtil(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int> path)
    {
        path.emplace_back(node);
        if (node == graph.size() - 1)
        {
            paths.emplace_back(path);
            path.clear();
            path.emplace_back(0);
        }
        for (auto it = graph[node].begin(); it != graph[node].end(); it++)
        {
            if (visited[*it] == false)
            {
                allPathsSourceTargetUtil(*it, graph, visited, path);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<bool> visited(graph.size(), false);
        vector<int> path;
        allPathsSourceTargetUtil(0, graph, visited, path);
        return paths;
    }
};
//int main(void)
//{
//    vector<vector<int>> graph = { {{4,3,1},{3,2,4},{3},{4},{} } };
//    Solution obj;
//    obj.allPathsSourceTarget(graph);
//}