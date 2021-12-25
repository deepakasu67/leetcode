#include <iostream>
#include <queue>
#include <set>
typedef long long unsigned int llud;
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n)
	{
		set<llud> dp;
		dp.insert(1);
		llud node = 1;
		auto it = dp.begin();
		int count = 0;
		while (count <= n)
		{
			node = *it;
			count++;
			dp.insert(2 * node);
			dp.insert(3 * node);
			dp.insert(5 * node);
			it++;
		}
		it = dp.begin();
		while (--n)
		{
			it++;
		}
		return *it;
	}
};

//int main(void)
//{
//	Solution obj;
//	obj.nthUglyNumber(1407);
//}