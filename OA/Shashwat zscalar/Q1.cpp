//
// Created by Deepak Sahu on 2/8/22.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int bestSumKStar(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> value, int k)
{
    unordered_map<int, vector<int>> adjList;

    for(int i =0; i < g_to.size();i++)
    {
        int u = g_from[i];
        int v = g_to[i];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int maxi = INT_MIN;
    for(auto it = adjList.begin(); it!= adjList.end(); it++)
    {
        if(it->second.size() <= k)
        {
            int sum = value[it->first];
            for(auto vecIt = it->second.begin(); vecIt!=it->second.end();it++)
            {
                sum+=value[*vecIt];
            }
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

//int main(void)
//{
//    int g_nodes = 5;
//    vector<int> g_from= {3,3,3,3};
//    vector<int> g_to = {1,2,4,5};
//    vector<int> values= {10,20,30,40,50};
//    int k = 2;
//    cout<<bestSumKStar(g_nodes,g_from,g_to,values,k);
//}