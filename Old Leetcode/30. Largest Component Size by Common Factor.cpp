#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include <algorithm>
#include <functional>

//Create graph using prime factors of every node value.
//how can we know that x& y are same component or not?
//Let x = 12, y = 15;
//
//prime factor of 12 = 2 * 2 * 3 . [[[ so create a bi - coonected graph by each distinct prime factor value. 12->2, 12->3 ]] ]
//prime factor of 15 = 3 * 5 [[[ 15->3, 15->5 ]] ]
//
//when we traverse the graph then 12 and 15 should be in same graph.
//

using namespace std;
class Solution {
public:
	int largestComponentSize(vector<int>& A) {
		int n, m, max_len, len;
		n = A.size();
		m = *max_element(A.begin(), A.end());
		max_len = 0;
		vector<bool> visited(m + 1);
		vector<vector<int>> adj(m + 1);
		unordered_set<int> seen(A.begin(), A.end());

		// helper function
		function<void(int)> dfs = [&](int s) {
			visited[s] = true;
			if (seen.count(s))
				max_len = max(++len, max_len);
			for (int& u : adj[s])
				if (!visited[u])
					dfs(u);
		};

		// prime factorization
		for (int x : A) {
			int a = x;
			for (int y = 2; y * y <= x; y++)
				if (x % y == 0) {
					while (x % y == 0)
						x /= y;
					adj[y].push_back(a);
					adj[a].push_back(y);
				}
			if (x > 1) {
				adj[x].push_back(a);
				adj[a].push_back(x);
			}
		}

		// get size of largest component
		for (int& s : A)
			if (!visited[s]) {
				len = 0;
				dfs(s);
			}

		return max_len;
	}
};

//int main(void)
//{
//    vector<int> nodes = { 4,6,15,35 };
//    Solution obj;
//    cout<<obj.largestComponentSize(nodes);
//}