#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int res = 0;

        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] - a[0] > b[1] - b[0];

            });

        for (int i = 0; i < n; i++)
        {
            if (i < n / 2) res += costs[i][0];
            else res += costs[i][1];
        }
        return res;
    }
};
//int main(void)
//{
//    vector<vector<int>> listOfPerson = { {10, 20},{30, 200},{400, 50},{30, 20 } };
//    Solution obj;
//    cout<< obj.twoCitySchedCost(listOfPerson);
//}