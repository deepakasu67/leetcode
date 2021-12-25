#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include"CreateATreeWithArray.h"
typedef long long int lli;
using namespace std;

class Solution {
	int lvl;
public:
	void averageOfLevelsUtils(TreeNode* root, int lvl, vector<pair<lli, int>> &sumAndCount)
	{
		if(root == nullptr)
		{
			if (this->lvl < lvl)
				this->lvl = lvl;
			return;
		}
		averageOfLevelsUtils(root->left, lvl + 1, sumAndCount);
		averageOfLevelsUtils(root->right, lvl + 1, sumAndCount);
		sumAndCount[lvl].first += root->val;
		sumAndCount[lvl].second++;

	}
    vector<double> averageOfLevels(TreeNode* root)
	{
		vector<pair<lli, int>> sumAndCount(100000, make_pair(0,0));
		averageOfLevelsUtils(root, 0, sumAndCount);
		//sumAndCount.resize(lvl);
		vector<double> result;
		for_each(sumAndCount.begin(), sumAndCount.begin() + lvl, [&result](pair<lli, int> &sumAndCount)
		{
				result.push_back(static_cast<double>(sumAndCount.first)/static_cast<double>(sumAndCount.second));
		});
		return result;
	}
};
//int main(void)
//{
//	Solution obj;
//	int a[] = { 2147483647,2147483647,2147483647 };
//	int n = sizeof(a) / sizeof(int);
//	TreeNode* root = build_tree(a, n);
//	obj.averageOfLevels(root );
//}