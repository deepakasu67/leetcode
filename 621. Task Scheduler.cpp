#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> charMap(26);
        for(int i = 0; i < tasks.size();i++)
        {
            charMap[tasks[i] - 'A']++;
        }
        sort(charMap.begin(), charMap.end());
        int maxElt =charMap[25];
        int idleSpots = (maxElt - 1) * n;

        for(int i = 24;i >=0 ; i--)
        {
            idleSpots -= min(maxElt - 1, charMap[i]);;
        }
        return idleSpots > 0 ? idleSpots + tasks.size() : tasks.size();
    }
};
//
//int main(void)
//{
//    
//}