#include<iostream>
#include<vector>
using namespace std;

pair<int, int> startAndEndOfMaxSubArray(vector<int>& a)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < a.size(); i++)
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    return { start, end };
}

pair<int, int> find_significant_energy_increase_iterative(vector<int>& A)
{
    vector<int> energyLevels;
    for (int i = 0; i < A.size() - 1; i++)
    {
        energyLevels.push_back(A[i + 1] - A[i]);
    }

    pair<int, int> maxSubArrayDetails = startAndEndOfMaxSubArray(energyLevels);
    maxSubArrayDetails.second = min((int)A.size(), maxSubArrayDetails.second + 1);
    return maxSubArrayDetails;
}


//int main(void)
//{
//    //vector<int> energyLevels = { 100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97 };
//    //vector<int> energyLevels = { 100,113,110,85,105,102,86,63,81,-101,94,95,105,110,115,120,125};
//	//vector<int> energyLevels = { 110,109,107,104,100 };
//	vector<int> energyLevels = { 0,0,10,7};
//    find_significant_energy_increase_iterative(energyLevels);
//}
