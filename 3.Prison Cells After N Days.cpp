#include<iostream>
#include <unordered_map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N)
	{
		vector<vector<int>> v(2, vector<int>());
		v[0].insert(v[0].begin(), cells.begin(), cells.end());
		v[1].insert(v[1].begin(), { 0,0,0,0,0,0,0,0 });
		unordered_map<string, int> hash;
		int i = 0;
		for( i = 1; i <= N; i++)
		{
			string cells;
			for(int j= 0; j < 8; j++)
			{
				bool isAdjacentSame;
				if (j == 0 || j == 7)
					isAdjacentSame = false;
				else
					isAdjacentSame = v[(i - 1) % 2][j - 1] == v[(i - 1) % 2][j + 1] ? true : false;
				
				v[i % 2][j] = isAdjacentSame;
				cells += to_string(v[i % 2][j]);
			}
			
			if(hash.find(cells) != hash.end())
			{
				break;
			}
			else
			{
				hash[cells] = i;
			}
		}

		i--;
		int Int = N % i != 0 ? N%i : N ;
		string str;
		for (auto &element : hash)
		{
			if(element.second == Int)
			{
				str = element.first;
			}
		}
		vector<int> result;
		for_each(str.begin(), str.end(), [&result](char ele)
		{
				result.push_back(ele - '0');
		});
    	
		return result;
    }
};
//int main(void)
//{
//	Solution obj;
//	vector<int> cells = { 0,1,0,1,1,0,0,1 };
//	obj.prisonAfterNDays(cells, 7);
//	//cout << 1000000000 % 14;
//	//cout << string((int)false);
//}