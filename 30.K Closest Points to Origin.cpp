#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    unsigned long long int distance(unsigned long long int x2, unsigned long long int y2)
    {
        return long(x2 * x2) +  long(y2 *y2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        multimap<double, vector<int>> distToPoints;
        vector<vector<int>> result;

        for (int i = 0; i < points.size(); i++)
        {
            int EucDistance = distance(points[i][0], points[i][1]);
            distToPoints.insert(pair<double, vector<int>>(EucDistance,points[i]));
        }
        int idx = 0;
        for (auto itr = distToPoints.begin(); idx < K && itr != distToPoints.end(); itr++, idx++)
        {
            result.push_back(itr->second);
        }

        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<vector<int>> points = {{1, 3}, { -2, 2}, { 2, -2}};
//    obj.kClosest(points, 2);
//}