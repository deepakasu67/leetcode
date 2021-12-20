#include <iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        if (n == 0)
            return tasks.size();
        map<char, int>freqOfChar;
        for (char task : tasks)
        {
            freqOfChar[task]++;
        }
        vector<pair<int, int>> freqOfCharVec(freqOfChar.begin(), freqOfChar.end());
        sort(freqOfCharVec.begin(), freqOfCharVec.end(), [](const auto& l, const auto& r)
            {
                if (l.second != r.second)
                    return l.second > r.second;

                return l.first < r.first;
            });

        int timeConsume = 0;
        int count = n;
        int last = 0;
        for (int j = 0; j < freqOfCharVec.size(); j++)
        {
            if (freqOfCharVec[j].second > 0)
            {
                while (freqOfCharVec[j].second-- != 0)
                {
                    count = n;
                    timeConsume++;
                    for (int i = j + 1; i < freqOfCharVec.size() && count != 0; i++)
                    {
                        if (freqOfCharVec[i].second > 0)
                        {
                            freqOfCharVec[i].second--;
                            count--;
                            timeConsume++;
                        }
                    }
                    if (j != freqOfCharVec.size() - 1)
                        timeConsume += count;
                }
            }
        }
        return timeConsume;
    }
};
//int main(void)
//{
//    vector<char> tasks = { 'A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','H','I','I', 'J', 'J', 'K', 'K', 'L', 'L', 'M', 'M', 'N', 'N', 'O', 'O', 'P', 'P', 'Q', 'Q', 'R', 'R', 'S', 'S', 'T', 'T', 'U', 'U', 'V', 'V', 'W', 'W', 'X', 'X', 'Y', 'Y', 'Z', 'Z'};
//    Solution obj;
//    obj.leastInterval(tasks, 2);
//}