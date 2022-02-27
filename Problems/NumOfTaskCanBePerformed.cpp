//
// Created by Deepak Sahu on 2/24/22.
//
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int countTheTask(int root, unordered_map<int, vector<int>> &adjList, vector<bool>& visited)
{
    if(visited[root] == true)
        return -1;

    visited[root] = true;
    int count  = 1;
    for(auto it = adjList[root].begin(); it != adjList[root].end(); it++)
    {
        count += countTheTask(*it, adjList, visited);
    }
    return count;
}

int task(int n, vector<int> &a, vector<int> &b)
{
    if(a.empty() || b.empty())
        return n;
    unordered_map<int, vector<int>> adjList;
    unordered_map<int,int> inorder;
    for(int i =1;i <= n; i++)
    {
        inorder[i] = 0;
    }
    for(int i = 0 ;i < a.size(); i++)
    {
        adjList[b[i]].push_back(a[i]);
        inorder[a[i]]++;
    }

    vector<bool> visited(n + 1, false);
    int count = 0;
    for(auto it = inorder.begin(); it != inorder.end(); it++)
    {
        if(it->second == 0) {
            if (!visited[it->first]) {
                count += countTheTask(it->first, adjList, visited);
            }
        }
    }
    int countFalse = 0;
    for(int i =1 ;i < visited.size(); i++)
    {
        if(visited[i] == false)
            count += countTheTask(i, adjList, visited);
    }

    return count;
}

//int main(void)
//{
//    vector<int> a = {1,2};
//    vector<int> b = {2,1};
//    int n = 2;
//    cout<<task(n, a, b);
//}