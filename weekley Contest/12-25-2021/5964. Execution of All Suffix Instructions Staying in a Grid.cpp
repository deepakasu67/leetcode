//
// Created by Deepak Sahu on 12/25/21.
//

#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s)
    {
        vector<int> ans;
        for(int i = 0; i < s.length(); i++)
        {
            int j = i;
            int r = startPos[0];
            int c = startPos[1];
            for (; j < s.length(); j++)
            {
                if(s[j] == 'R')
                {
                    c++;
                }
                else if(s[j] == 'D')
                {
                    r++;
                }
                else if(s[j] == 'U')
                {
                    r--;
                }
                else if(s[j] == 'L')
                {
                    c--;
                }
                if(r < 0 || c < 0 || r >= n || c >= n)
                    break;
            }
            ans.push_back(j-i);
        }
        return ans;
    }
};
//int main(void)
//{
////    vector<int> startPos = {0,1};
////    string s = "RRDDLU";
////    int n = 3;
//    vector<int> startPos = {1,1};
//    string s = "LURD";
//    int n = 2;
//    Solution().executeInstructions(n,startPos,s);
//}