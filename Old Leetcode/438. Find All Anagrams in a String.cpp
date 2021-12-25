#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return {};
        vector<int> pCharMap(26);
        vector<int> sCharMap(26);
        vector<int> result;
        for(int i = 0 ; i<p.size();i++)
        {
            pCharMap[p[i] - 'a']++;
        }
        int trail = 0;
        for(int lead = 0; lead < s.size();lead++)
        {
            sCharMap[s[lead] - 'a']++;
            if((lead - trail) + 1 ==  p.size())
            {
                bool everyCountIsSame = true;
                for(int i = 0; i < 26;i++)
                {
                    if(pCharMap[i] != sCharMap[i])
                    {
                        everyCountIsSame = false;
                        break;
                    }
                }
                if(everyCountIsSame == true)
                {
                    result.push_back(trail);
                }
                sCharMap[s[trail] - 'a']--;
                trail++;
            }
        }
        return result;
    }
};

//int main(void)
//{
//    string s = "abab";
//    string p = "ab";
//    Solution obj;
//    obj.findAnagrams(s, p);
//}