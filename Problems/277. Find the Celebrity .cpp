//
// Created by Deepak Sahu on 12/29/21.
//

#include<vector>
#include<iostream>
using namespace std;
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    vector<vector<int>> relationShip;
public:

    Solution(vector<vector<int>> &relationShip)
    {
        this->relationShip = relationShip;
    }

    bool knows(int a, int b)
    {
        return this->relationShip[a][b];
    }
    int findCelebrity(int n) {

        int candidate = 0;
        bool isCandidateSelected = false;
        for(int i = 1; i < n; i++)
        {
            if(!knows(i, candidate))
            {
                isCandidateSelected = true;
                candidate = i;
            }
        }
        if(isCandidateSelected == false)
            return -1;
        int count = 0;
        for(int i =0;i < n; i++)
        {
            if(knows(i,candidate))
                count++;
        }
        return count == n ? candidate : -1;
    }
};

//int main(void)
//{
//    vector<vector<int>> relationship = {{1,1,0},{0,1,0},{1,1,1}};
//    cout<<Solution(relationship).findCelebrity(2);
//}