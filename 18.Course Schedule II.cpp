#include <queue>
#include<numeric>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findOrderUtil(int numCourses, vector<vector<int>>& adjList)
    {
        vector<int> inDegree(numCourses, 0);
        for (int u = 0; u < adjList.size(); u++)
        {
            for (int v = 0; v < adjList[u].size(); v++)
            {
                inDegree[adjList[u][v]]++;
            }
        }
        vector<int> result;
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
            result.push_back(vertex);
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
            return result;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<std::vector<int>>& prerequisites)
    {
        vector<int> result(numCourses);
        if (prerequisites.empty())
        {
            if (numCourses == 0)
                return {};
            iota(result.begin(), result.end(), 0);
            return result;
        }
        vector<vector<int>> adjList(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return findOrderUtil(numCourses, adjList);
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<vector<int>> prereq = { {1,0 }, { 2,0 }, { 3,1 }, { 3,2 } };
//    obj.findOrder(4, prereq);
//}
