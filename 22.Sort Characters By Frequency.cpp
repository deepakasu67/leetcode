#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s.empty())
        {
            return "";
        }
        unordered_map<char, int> charCount;
        for (int i = 0; i < s.length(); i++)
        {
            charCount[s[i]]++;
        }
        multimap<int, char, greater<int>> countChar;
        for (auto it = charCount.begin(); it != charCount.end(); it++)
        {
            countChar.insert(pair<int, char>(it->second,it->first));
        }

        string result;
        for (auto it = countChar.begin(); it != countChar.end(); it++)
        {
            result += string(it->first, it->second);
        }
            return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.frequencySort("");
//}