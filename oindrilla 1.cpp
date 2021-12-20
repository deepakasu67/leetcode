#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//void printMatrx(vector<vector<char>>& mat)
//{
//	for (int i = 0; i < mat.size(); i++)
//	{
//		for (int j = 0; j < mat[i].size(); j++)
//		{
//			cout << mat[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

vector<vector<char>> solution(vector<vector<char>> matrix)
{
	vector<pair<int, int>> figure;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == 'F')
				figure.push_back({ i,j });
		}
	}
	vector<vector<char>> oldMatrix;
	sort(figure.begin(), figure.end());
	for (int j = 0; j < matrix.size(); j++)
	{
		oldMatrix = matrix;
		bool foundObst = false;
		for (int i = figure.size()-1; i >= 0; i--)
		{
			int r = figure[i].first;
			int c = figure[i].second;
			if (r + 1 == matrix.size() || matrix[r + 1][c] == '#' )
			{
				foundObst = true;
				break;
			}
			matrix[r][c] = '.';
			matrix[r + 1][c] = 'F';
			figure[i].first++;
		}
		if (foundObst == true)
		{
			return oldMatrix;
		}
		printf("-------\n");
		//printMatrx(matrix);
	}
	return matrix;
}
//
//int main(void)
//{
//	vector<vector<char>> mat = 
//	{
//		{'F','F','F'},
//		{'.','.','.'},
//		{'.','.','.'},
//		{'.','.','.'},
//		{'.','.','.'},
//		{'.','.','.'},
//		{'.','.','.'},
//		{'.','.','.'}
//	};
//	//printMatrx(mat);
//	vector<vector<char>> ans = solution(mat);
//	printf("-----\n");
//	//printMatrx(ans);
//}