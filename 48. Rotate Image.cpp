// An efficient C++ program to find sum of all subsquares of size k x k
#include <iostream>
#include<vector>
using namespace std;

// Size of given matrix


void printSumTricky(vector<vector<int>> &mat, int k)
{
	int n = mat.size();
	// k must be smaller than or equal to n
	if (k > n) return;

	// 1: PREPROCESSING
	// To store sums of all strips of size k x 1

	vector<vector<int>> stripSum(n, vector<int>(n, 0));

	// Go column by column
	for (int j = 0; j < n; j++)
	{
		// Calculate sum of first k x 1 rectangle in this column
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += mat[i][j];
		stripSum[0][j] = sum;

		// Calculate sum of remaining rectangles
		for (int i = 1; i < n - k + 1; i++)
		{
			sum += (mat[i + k - 1][j] - mat[i - 1][j]);
			stripSum[i][j] = sum;
		}
	}


	// 2: CALCULATE SUM of Sub-Squares using stripSum[][]
	for (int i = 0; i < n - k + 1; i++)
	{
		// Calculate and print sum of first subsquare in this row
		int sum = 0;
		for (int j = 0; j < k; j++)
			sum += stripSum[i][j];
		cout << sum << " ";

		// Calculate sum of remaining squares in current row by
		// removing the leftmost strip of previous sub-square and
		// adding a new strip
		for (int j = 1; j < n - k + 1; j++)
		{
			sum += (stripSum[i][j + k - 1] - stripSum[i][j - 1]);
			cout << sum << " ";
		}

		cout << endl;
	}
}

//// Driver program to test above function
//int main()
//{
//	vector<vector<int>> mat= {
//			{9, 7, 8, 9, 2},
//			{6, 9, 9, 6, 1},
//			{4, 10, 1, 3, 10},
//			{18, 2, 3, 9, 3},
//			{4, 6, 8, 5, 21}
//	};
//	int k = 3;
//	printSumTricky(mat, k);
//	return 0;
//}
