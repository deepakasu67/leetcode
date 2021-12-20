#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool findLoop(int numCourses, vector<vector<int>>& adjList)
    {
        vector<int> inDegree(numCourses, 0);
        for (int u= 0; u< adjList.size(); u++)
        {
            for (int v = 0; v < adjList[u].size(); v++)
            {
                inDegree[adjList[u][v]]++;
            }
        }

        queue<int> bfsQ;
        int count = 0;
        for (int i = 0; i < inDegree.size(); i++)
        {
            if (inDegree[i] == 0)
                bfsQ.push(i);
        }

        while (!bfsQ.empty())
        {
            int vertex = bfsQ.front();
            bfsQ.pop();
            for (auto it = adjList[vertex].begin(); it != adjList[vertex].end(); it++)
            {
                if (--inDegree[*it] == 0)
                {
                    bfsQ.push(*it);
                }
            }
            count++;
        }
        if (count == numCourses)
        {
            return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        if (prerequisites.empty())
        {
            return true;
        }
        vector<vector<int>> adjList(numCourses,vector<int>());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return findLoop(numCourses, adjList);
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<vector<int>> preReq = { {1, 0}};
//    cout<<obj.canFinish(2,preReq);
//}