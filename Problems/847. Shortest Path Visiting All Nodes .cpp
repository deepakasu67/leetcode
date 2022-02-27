//
// Created by Deepak Sahu on 2/26/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int pathLengthToVisit(unordered_map<int, vector<int>>& adjList, int node, vector<int>& visited)
    {
        if(visited[node] > 0)
            return visited[node] + 1;

        int pathLengthToAllNonVisited = INT_MAX;
        for(auto it = adjList[node].begin(); it != adjList[node].end(); it++)
        {

        }
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adjList;
        for(int i = 0 ; i < graph.size(); i++)
        {
            for(int j =0; j < graph[i].size(); j++)
            {
                adjList[i].push_back(graph[i][j]);
                adjList[graph[i][j]].push_back(i);
            }
        }

    }
};

//int main(void)
//{
//
//}