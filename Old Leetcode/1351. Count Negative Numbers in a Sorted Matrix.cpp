#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int output = 0;
        vector<int> v;
        vector<int>::iterator it;
        for (int i = 0; i < grid.size(); i++)
        {
            v = grid[i];
            int coloumn = v.size();
            it = std::upper_bound(v.begin(), v.end(), -1, std::greater_equal<int>());
            if (it != v.end())
            {
                int foundIndex = it - v.begin();
                if (v[foundIndex] < 0)
                {
                    output += (coloumn - foundIndex);
                }
            }
        }
        return output;
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<vector<int>> v{ {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-1} };
//    cout << obj.countNegatives(v);
//}