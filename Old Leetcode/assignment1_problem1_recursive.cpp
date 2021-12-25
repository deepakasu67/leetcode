#include<vector>
#include<iostream>
#include<math.h>
using namespace std;


pair<int, pair<int,int>> maxSubArray(vector<int>& nums, int l, int r) 
{
    if (l > r) {
        return { INT_MIN, {-1,-1} };
    }
    int mid= l + (r - l) / 2, ml = 0, mr = 0;
    auto lmax = maxSubArray(nums, l,  mid - 1);
    auto rmax = maxSubArray(nums, mid + 1, r);
    int leftCrossing = mid ;
    for (int i = mid- 1, sum = 0; i >= l; i--) {
        sum += nums[i];
        if (sum >= ml)
        {
            ml = sum;
            leftCrossing = i;
        }
    }

    int rightCrossing = mid;
    for (int i = mid+ 1, sum = 0; i <= r; i++) {
        sum += nums[i];
        if (sum >= mr)
        {
            mr = sum;
            rightCrossing = i;
        }
    }
    int crossingSum = ml + mr + nums[mid];
    pair<int, pair<int,int>> crossingDetail = { crossingSum, {leftCrossing,rightCrossing} };
    int maximumOfAll = max(max(lmax.first, rmax.first), crossingDetail.first);
    if (maximumOfAll == lmax.first)
        return lmax;
    else if (maximumOfAll == rmax.first)
        return rmax;
    else
        return crossingDetail;
}

pair<int, int> find_significant_energy_increase_Recursive(vector<int>& A)
{
	vector<int> energyLevels;
	for (int i = 0; i < A.size() - 1; i++)
	{
		energyLevels.push_back(A[i + 1] - A[i]);
	}

    pair<int, pair<int,int>> maxSubArrayDetails = maxSubArray(energyLevels, 0, energyLevels.size() - 1);
    pair<int, int> startEndOfMaxSubarray = maxSubArrayDetails.second;
    startEndOfMaxSubarray.second = min((int)A.size(), startEndOfMaxSubarray.second + 1);
	return startEndOfMaxSubarray;
}

//int main(void)
//{
//    //vector<int> energyLevels = { 100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97 };
//    //vector<int> energyLevels = { 100,113,110,85,105,102,86,63,81,-101,94,95,105,110,115,120,125};
//	//vector<int> energyLevels = { 110,109,107,104,100 };
//	vector<int> energyLevels = { 0,0,10, 7 };
//    find_significant_energy_increase_Recursive(energyLevels);
//}