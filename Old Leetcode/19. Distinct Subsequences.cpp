#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int allSubSeqToFormTFromS(string& s, string& t, int sIdx, int tIdx, vector<vector<int>> &dp)
    {
        if (tIdx == t.length()) //if we exhaust t then we must have found the match
            return 1;

        if (sIdx == s.length()) //if we exhaust the s then we havent found the match
            return 0;

        if (dp[sIdx][tIdx] > -1)
        {
            return dp[sIdx][tIdx];
        }
        
        if (s[sIdx] == t[tIdx])
        {
            int includeBoth = allSubSeqToFormTFromS(s, t, sIdx + 1, tIdx + 1, dp);
            int excludeTAndIncrementS = allSubSeqToFormTFromS(s, t, sIdx + 1, tIdx, dp); // we are checking all the position in S and we need to match it to T

            dp[sIdx][tIdx] = includeBoth + excludeTAndIncrementS;//add all the result comming by including and excluding
        }
        else
        {
            dp[sIdx][tIdx] = allSubSeqToFormTFromS(s, t, sIdx + 1, tIdx, dp); //if it doesn't matches then we look for match .
        }
        return dp[sIdx][tIdx];
    }

    int numDistinct(string s, string t) 
    {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return allSubSeqToFormTFromS(s, t, 0, 0, dp);
    }
};

//vector<long> sumValues(vector<int> parents, vector<int> startPoint, vector<int> jumpLength) 
//{
//    vector<long> answ;
//    for (int i = 0; i < startPoint.size(); i++)
//    {
//        int start = startPoint[i];
//        int jump = jumpLength[i];
//        int sum = 0;
//        int step = 0;
//        for (;start > -1;)
//        {
//            if(step % jump == 0)
//                sum += start;
//            start = parents[start];
//            step++;
//        }
//        answ.push_back(sum);
//    }
//    return answ;
//}
//int main(void)
//{
//  /*  Solution obj;
//    cout<<obj.numDistinct("babgbag", "bag");*/
//    vector<int> parent = { -1,0,1,1,2,4 };
//    vector<int> startpoint = { 5, 4};
//    vector<int> jumpLength= {1, 2};
//    sumValues(parent, startpoint, jumpLength);
//}