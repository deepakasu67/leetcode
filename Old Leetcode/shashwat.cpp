#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include <numeric>
#include<unordered_set>
#include<math.h>
using namespace std;

//int costToBuildEachModule(unordered_map<char, vector<char>>& adjList, char node, unordered_set<char>& visited)
//{
//	if (visited.find(node) != visited.end())
//	{
//		return 0;
//	}
//	
//	visited.insert(node);
//	int dependentModule = 1;
//	for (auto it = adjList[node].begin(); it != adjList[node].end(); it++)
//	{
//		dependentModule += costToBuildEachModule(adjList, *it, visited);
//	}
//	return dependentModule;
//}
//
//vector<string> applicationBuilder(vector<string> lines)
//{
//	if (lines.size() == 0)
//		return {};
//    unordered_map<char, vector<char>> adjList;
//	unordered_set<char> nodes;
//	for (string& str : lines)
//	{
//		for (char& ch : str)
//		{
//			if(ch != ',')
//				nodes.insert(ch);
//		}
//	}
//	for (string& str : lines)
//	{
//		for (int i = 1; i < str.length(); i++)
//		{
//			if (!adjList.count(str[i]))
//			{
//				adjList[str[i]] = vector<char>();
//			}
//			adjList[str[i]].push_back(str[0]);
//		}
//	}
//
//	vector<string> ans;
//	for (auto it = nodes.begin(); it!=nodes.end(); it++)
//	{
//		string ch(1,*it);		
//		unordered_set<char> visited;
//		int cost = costToBuildEachModule(adjList, *it, visited);
//		ch = ch + ',' + to_string(cost);
//		ans.push_back(ch);
//	}
// 	 sort(ans.begin(), ans.end());
//	 return ans;
//}
 
int getSumIsValid(vector<int> &arr, int x, int maxMinutes) {
	int val = 0;
	for (int i = 0; i < arr.size(); i++) {
		val += ceil(double(arr[i]) /double( x));
			if (val > maxMinutes) {
				return false;
			}
	}
	return true;
}

//int minimumcandiesPerHour(vector<int> donutBoxes, int numMinutes)
//{
//	int maxDonouts = *max_element(donutBoxes.begin(), donutBoxes.end());
//
//	int l = 1, h = maxDonouts;
//
//	while (l < h)
//	{
//		int mid = l + (h - l) / 2;
//		if(getSumIsValid(donutBoxes, mid, numMinutes))
//		{
//			h = mid;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//	return l ;
//}


//// Driver code
//int main()
//{
//	//vector<string> lines = { "REIH", "HGI", "EI", "G", "I"};
//	vector<string> lines = { "xy"};
//	applicationBuilder(lines);
//}

//int main(void)
//{
//	//vector<int> donuts = { 3,2,1,4,5,2,3,4};
//	vector<int> donuts = { 4 ,9,11,17};
//	cout<<minimumcandiesPerHour(donuts, 8);
//	//cout<<bs(donuts, 8, 0, donuts.size() - 1);
//}

