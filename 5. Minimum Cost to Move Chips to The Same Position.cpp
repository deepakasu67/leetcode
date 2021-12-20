#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position)
    {
        int odd = 0, even = 0;
        for(int i=0;i < position.size(); i++)
        {
            if (position[i] % 2 == 1)
                odd++;
            else
                even++;
        }
        return odd > even ? even : odd;
    }
};
//
//int main(void)
//{
//    Solution obj;
//    vector<int> positions = { 6, 4, 7, 8, 2, 10, 2, 7, 9, 7 };
//    cout<<obj.minCostToMoveChips(positions);
//}