//https://leetcode.com/problems/destination-city/
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for_each(begin(paths), end(paths), [&](auto paths)
        {
            mp[paths[0]] = paths[1];
        });
        auto prev = mp.begin();
        for (auto itr= mp.begin(); itr != mp.end(); )
        {
            prev = itr;
            auto got = mp.find(itr->second);
            if (got == mp.end())
            {
                break;
            }
            itr = got;
        }
        return prev->second;
    }
};
//int main(void)
//{
//    vector<vector<string>> paths = { {"B","C"}};
//    Solution obj;
//    obj.destCity(paths);
//}