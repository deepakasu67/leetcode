#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        unordered_map<int, bool> visitedWithColor; //true = red , false = blue
        queue<pair<int,bool>> q;
        for (int i = 0; i < graph.size(); i++) // iterating through the components
        {
            if (visitedWithColor.find(i) == visitedWithColor.end())
            {
                q.push({ i,true });
                while (!q.empty())
                {
                    int top = q.front().first;
                    for (int i = 0; i < graph[top].size(); i++)
                    {
                        auto it = visitedWithColor.find(graph[top][i]);
                        if (it == visitedWithColor.end())
                        {
                            auto node = make_pair(graph[top][i], !q.front().second);
                            visitedWithColor.insert(node);
                            q.push(node);
                        }
                        else
                        {
                            if (it->second == q.front().second)
                            {
                                return false;
                            }
                        }
                    }
                    visitedWithColor.insert(q.front());
                    q.pop();
                }
            }
        }
        return true;
    }
};

//int main(void)
//{
//    vector<vector<int>> adjList ={ 
//        {},
//        {2, 4, 6},
//        {1, 4, 8, 9},
//        {7, 8},
//        {1, 2, 8, 9},
//        {6, 9},
//        {1, 5, 7, 8, 9},
//        {3, 6, 9},
//        {2, 3, 4, 6, 9},
//        {2, 4, 5, 6, 7, 8}};
//    Solution obj;
//    cout<<obj.isBipartite(adjList);
//}