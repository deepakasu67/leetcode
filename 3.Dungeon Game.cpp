#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMiniHealth(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>>& minHealth)
    {
        if (i >= dungeon.size() || j >= dungeon[0].size() )
            return INT_MIN;
        
        if (minHealth[i][j] != INT_MIN)
            return minHealth[i][j];

        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1)
        {
            return dungeon[i][j];
        }

        int right = calculateMiniHealth(dungeon, i, j + 1, minHealth);
        int down = calculateMiniHealth(dungeon, i + 1, j, minHealth);

        minHealth[i][j] = min(0, max(down, right)) + dungeon[i][j];// for right corner, this would fail as down and right would have int_min. hence whole min would be int_min.
        //so, for this we have done line 30, to make sure int_min is not comming all the side
        return minHealth[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        vector<vector<int>> minimumHealth(dungeon.size(), vector<int>(dungeon[0].size(), INT_MIN));
        minimumHealth[dungeon.size() - 1][dungeon[0].size() - 1] = minimumHealth[dungeon.size() - 1][dungeon[0].size() - 1];
        int result = calculateMiniHealth(dungeon, 0, 0, minimumHealth);
        return 1 + abs(min(0, result));
    }
};

//int main(void)
//{
//    vector<vector<int>> dungeon = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
//    Solution obj;
//    cout<<obj.calculateMinimumHP(dungeon);
//}