#include<iostream>
#include<vector>
#include<cmath>
using namespace  std;
using namespace  std;
class Solution {
	int m, n;
public:
	void calculateMinimumHpUtil(vector<vector<int>>& dungeon,
		vector<vector<bool>>& visited,
		int& maxNegative,
		int x, int y, int currSum)
	{
		if (x < 0 || y < 0 || x >= m || y >= n)
		{
			return;
		}
		if (x == m - 1 && y == n - 1 && currSum + dungeon[x][y] < 0)
		{
			if (currSum + dungeon[x][y] > maxNegative)
			{
				maxNegative = currSum + dungeon[x][y];
			}
		}
		if (visited[x][y] == false)
		{
			visited[x][y] = true;
			calculateMinimumHpUtil(dungeon, visited, maxNegative, x, y + 1, currSum + dungeon[x][y]); //west
			calculateMinimumHpUtil(dungeon, visited, maxNegative, x + 1, y, currSum + dungeon[x][y]); //south
		}
		visited[x][y] = false;
	}
	int calculateMinimumHP(vector<vector<int>>& dungeon)
	{
		m = dungeon.size();
		n = dungeon[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));
		int maxNegative = INT_MIN;
		calculateMinimumHpUtil(dungeon, visited, maxNegative, 0, 0, 0);
		return maxNegative == INT_MIN ? 1 : abs(maxNegative) + 1;
	}
};

//int main(void)
//{
//	Solution obj;
//	/*vector<vector<int>> dungeon = { {-2, -3, 3},
//								  {-2, -3, 3},
//								  {-5, -10, 1 },
//								  {10, 30, -5} };*/
//	vector<vector<int>> dungeon = { {-3,5} };
//	obj.calculateMinimumHP(dungeon);
//}