#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string weight(string &str)
    {
        string  key;
        for(int i =0; i < str.size() - 1; i++)
        {
            int diff = (str[i] - str[i + 1]);
            if (diff < 0)
                diff += 26;
            key = key + '#' + to_string(diff);
        }
        return key;
    }
    vector<vector<string>> groupStrings(vector<string>& strings)
    {
        unordered_map<string, vector<string>> result;
        for(int i =0; i < strings.size(); i++)
        {
            string key = weight(strings[i]);
            result[key].push_back(strings[i]);
        }
        vector<vector<string>> final;
        for(auto it = result.begin(); it!= result.end();it++)
        {
            final.push_back(it->second);
        }
        return final;
    }
};
//
//int main(void)
//{
//    vector<string> input = { "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
//    Solution obj;
//    obj.groupStrings(input);
//}
