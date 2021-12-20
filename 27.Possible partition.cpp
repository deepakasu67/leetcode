#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool possibleBipartitionUtil(vector<vector<int>>& adj, vector<int>& color, int src)
    {
        
        queue<int> q;
        color[src] = 1;
        q.push(src);
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            for (auto it = adj[vertex].begin(); it != adj[vertex].end(); it++)
            {
                if (color[*it] == -1)
                {
                    color[*it] = !color[vertex] ;
                    q.push(*it);
                }
                if (color[*it] == color[vertex])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjancyList(N + 1, vector<int>());
        for (int i = 0; i < dislikes.size(); i++)
        {
            adjancyList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjancyList[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(N + 1, -1);
        for (int i = 1; i < color.size(); i++)
        {
            if (color[i] == -1)
            {
                if (!possibleBipartitionUtil(adjancyList, color, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<vector<int>> inp = { {1,2} ,{2,3},{3,4},{4,5},{1,5} };
//    cout<<obj.possibleBipartition(5,inp);
//}