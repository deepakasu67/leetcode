#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int countPoints(string rings) {

        vector<vector<bool>> ringsFreq(10,vector<bool>(3,false));
        int count = 0;
        for (int i = 0; i < rings.length(); i += 2)
        {
            int col = 0;
            if (rings[i] == 'R')
                col = 0;
            else if (rings[i] == 'G')
                col = 1;
            else if (rings[i] == 'B')
                col = 2;
            
            ringsFreq[rings[i+1]-'0'][col] = true;

        }
        for (int i = 0; i < ringsFreq.size(); i++)
        {
            if (ringsFreq[i][0] == true
                && ringsFreq[i][1] == true
                && ringsFreq[i][2] == true)
                count++;
        }
        return count;


    }
};

//int main(void)
//{
//    Solution().countPoints("G4");
//}