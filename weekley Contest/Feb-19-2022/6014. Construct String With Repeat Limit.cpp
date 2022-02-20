//
// Created by Deepak Sahu on 2/19/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<char,int> pi;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> charFreq(26,0);
        for(char ch : s)
        {
            charFreq[ch-'a']++;
        }
        priority_queue<pi, vector<pi> > pq;
        for(int i =0;i < charFreq.size(); i++)
        {
            if(charFreq[i] == 0)
                continue;
            pq.push({'a' + i,charFreq[i]});
        }
        string result;
        while(pq.size() >= 2)
        {
            int tempRepeatLimit = repeatLimit;
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            if(result.back() == first.first)
                tempRepeatLimit--;
            int minRepeatChar = min(first.second, tempRepeatLimit);

            first.second -= minRepeatChar;
            result += string(minRepeatChar,first.first) + second.first;
            second.second--;

            if(first.second > 0)
                pq.push({first.first,first.second});
            if(second.second > 0)
                pq.push({second.first, second.second});
        }
        while(pq.size())
        {
            int tempRepeatLimit = repeatLimit;
            auto first = pq.top();
            if(result.back() == first.first)
                tempRepeatLimit--;
            result += string(min(tempRepeatLimit,pq.top().second),pq.top().first);
            pq.pop();
        }
        return result;
    }
};

//int main(void)
//{
//    string s = "aababab";
//    int repeatLimit = 2;
//    cout<<Solution().repeatLimitedString(s,repeatLimit);
//}
