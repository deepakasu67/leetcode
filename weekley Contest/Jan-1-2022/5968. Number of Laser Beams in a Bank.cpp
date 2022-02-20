//
// Created by Deepak Sahu on 1/1/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        int prev = 0;
        for(int i =0; i < bank.size(); i++)
        {
            int current= 0;
            for(int j =0;j < bank[i].size(); j++)
            {
                if(bank[i][j] == '1')
                    current++;
            }
            if(current!=0) {
                count += prev * current;
                prev = current;
            }
        }
        return count;
    }
};

//int main(void)
//{
//    vector<string> bank = {"011001","000000","010100","001000"};
//    cout<<Solution().numberOfBeams(bank);
//}