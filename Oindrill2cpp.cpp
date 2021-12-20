#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<string> charMessageStatistics(vector<string>& members, vector<string>& message)
{
	unordered_map<string, int> count1;
	for (auto& x : members)
		count1['@' + x] = 0;

	vector<string> ans;
	int countAll = 0;
	for (int i = 0; i < message.size(); i++)
	{
		unordered_set<string> uniqueIds;
		int prevCount = countAll;
		for (int j = 0; j < message[i].length(); j++)
		{
			if (message[i][j] == '@')
			{
				int idx = message[i].find(' ', j);
				if (idx != string::npos)
				{
					string ids = message[i].substr(j, abs(idx - j));
					if (ids == "@all")
						countAll++;
					else
						uniqueIds.insert(ids);
				}
			}
		}
		if(countAll == prevCount)
			for (auto it = uniqueIds.begin(); it != uniqueIds.end(); it++)
			{
				if (count1.count(*it))
				{
					count1[*it]++;
				}
			}
	}

	while (countAll)
	{
		for (auto& it : count1)
		{
			it.second++;
		}
		countAll--;
	}

	for (auto& it : count1)
	{
		ans.push_back(it.first+"="+to_string(it.second));
	}
	return ans;
}

// 