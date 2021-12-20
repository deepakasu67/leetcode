#include<iostream>
#include<vector>
#include<utility>
using namespace std;

pair<int,int> idxOfMaxSubArray(vector<int>& nums)
{
	int globalMaxSubarray = INT_MIN;
	pair<int, int> startEndOfSubArray;
	for (int i = 0; i < nums.size(); i++)
	{
		int localMaxSubarray = 0;
		for (int j = i; j < nums.size(); j++)
		{
			localMaxSubarray += nums[j];
			if (localMaxSubarray > globalMaxSubarray)
			{
				startEndOfSubArray = make_pair(i, j);
				globalMaxSubarray = localMaxSubarray;
			}
		}
	}
	return startEndOfSubArray;

}

pair<int, int> find_significant_energy_increase_brute(vector<int>& A)
{
	vector<int> energyLevels;
	for (int i = 0; i < A.size() - 1; i++)
	{
		energyLevels.push_back(A[i+1] - A[i]);
	}
	pair<int, int> maxSubArray =  idxOfMaxSubArray(energyLevels);
	maxSubArray.second= min((int)A.size(), maxSubArray.second+1);
	return maxSubArray;
}

//int main(void)
//{
//	//vector<int> energyLevels = { 100,113,110,85,105,102,86,63,81,-101,94,95,105,110,115,120,125};
//	//vector<int> energyLevels = { 110,109,107,104,100 };
//	//vector<int> energyLevels = { 100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97 };
//	vector<int> energyLevels = { 0,0,10, 7 };
//
//	auto result = find_significant_energy_increase_brute(energyLevels);
//	cout << result.first << "," << result.second;
//}