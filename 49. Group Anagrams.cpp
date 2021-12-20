#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> groupAnagrams;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            groupAnagrams[str].push_back(strs[i]);
        }

        for (auto it = groupAnagrams.begin(); it != groupAnagrams.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};

//int main(void)
//{
//    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
//    Solution obj;
//    obj.groupAnagrams(strs);
//}