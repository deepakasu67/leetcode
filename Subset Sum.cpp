#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(vector<int>& v, int curIdx, int target, int sum)
{
	if (target == sum)
	{
		return true;
	}

	if (curIdx >= v.size() || sum > target)
	{
		return  false;
	}
	return subsetSum(v, curIdx + 1, target, sum)  // doesn't include
		   || subsetSum(v, curIdx + 1, target, sum + v[curIdx]); //include
}

//int main(void)
//{
//	vector<int> v = { 1, 2, 3, 7, 16 };
//	int target = 10;
//	cout << subsetSum(v, 0,target,0);
//}