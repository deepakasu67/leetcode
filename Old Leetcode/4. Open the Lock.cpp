#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>


using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> visited;
        unordered_set<string> deadEnds(deadends.begin(), deadends.end());
        queue<string> q;
        if (deadEnds.count(target))
            return -1;
        if (target == "0000")
            return 0;
        q.push("0000");
        int steps = 1;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string curr = q.front();
                if (curr == target)
                    return steps;
                q.pop();
                for(int i = 0; i < curr.size(); i++)
                {
                    for (int diff = 1; diff < 10; diff+=8) //diff+=8 becuase we can rotate wheel 1up or 1down.For example, 2can go 1 or 3 ,1 <-2 -> 3
                    {
                        int temp = curr[i] - '0';
                        curr[i] = ((temp + diff)%10) + '0';
                        if (!deadEnds.count(curr) && !visited.count(curr))
                        {
                            q.push(curr);
                        }
                        visited.insert(curr);
                        curr[i] = temp + '0';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
//int main(void)
//{
//    vector<string> deadEnds = { "0201","0101","0102","1212","2002" };
//    string target = "0202";
//    Solution obj;
//    cout<<obj.openLock(deadEnds, target);
//}