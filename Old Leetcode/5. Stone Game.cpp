#include<iostream>
#include<numeric>
#include<vector>
#include<string>
using namespace std;

enum class TURN
{
    alice,
    bob
};

class Solution {
public:
    bool stoneGameUtil(vector<int>& piles, int start, int end, int target, int alice, int bob, TURN turn)
    {
        string key;
        if (turn == TURN::alice)
        {
            key = to_string(start) + "|" + to_string(end) + "|" + to_string(alice);
        }
        else
        {
            key = to_string(start) + "|" + to_string(end) + "|" + to_string(bob);
        }
        if (start > end)
        {
            if (alice >= target / 2)
                return true;
            else
                return false;
        }
        if (alice >= target / 2)
            return true;
        bool aliceStart = false, aliceEnd = false, bobStart = false, bobEnd = false;
        if (turn == TURN::alice)
        {
            aliceStart = stoneGameUtil(piles, start + 1, end, target, alice + piles[start], bob, TURN::bob);
            aliceEnd = stoneGameUtil(piles, start, end - 1, target, alice + piles[end], bob, TURN::bob);
        }
        if (turn == TURN::bob)
        {
            bobStart = stoneGameUtil(piles, start + 1, end, target, alice, bob + piles[start], TURN::alice);
            bobEnd = stoneGameUtil(piles, start, end - 1, target, alice, bob + piles[end], TURN::alice);
        }
        return aliceStart || aliceEnd || bobStart || bobEnd;
    }
    bool stoneGame(vector<int>& piles) 
    {
        int target = accumulate(piles.begin(), piles.end(), 0);
        return stoneGameUtil(piles, 0, piles.size() - 1, target, 0, 0, TURN::alice);

    }
};
//
//int main(void)
//{
//    vector<int> piles = { 1,5,2};
//    Solution obj;
//    cout<<obj.stoneGame(piles);
//}