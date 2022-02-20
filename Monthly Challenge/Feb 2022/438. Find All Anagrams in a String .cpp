//
// Created by Deepak Sahu on 2/2/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> freqMap(26,0);
        for(int i =0; i < p.length(); i++)
        {
            freqMap[p[i]-'a']++;
        }
        vector<int> result;
        int i =0;
        for(int j = 0; j < s.length(); j++)
        {
            if(j-i + 1 == p.size())
            {

            }
        }
    }
};
//int main(void)
//{
//    cout<<"deepak";
//}