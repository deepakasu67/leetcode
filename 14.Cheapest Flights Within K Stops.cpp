//using dijkstra's algorithm
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& f : flights)
            adj[f[0]].push_back({ f[1], f[2] });

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
        Q.push({ 0, src, K + 1 });

        while (!Q.empty()) {
            vector<int> top = Q.top();
            Q.pop();
            int d = top[0];
            int u = top[1];
            int k = top[2];
            if (dst == u) return d;
            if (k > 0) {
                for (pair<int, int>& v : adj[u])
                    Q.push({ d + v.second, v.first, k - 1 });
            }
        }
        return -1;
    }
};