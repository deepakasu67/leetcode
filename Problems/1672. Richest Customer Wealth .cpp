//
// Created by Deepak Sahu on 1/30/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> personWealth(accounts.size(),0);

        for(int i =0;i < accounts.size(); i++)
        {
            for(int j = 0; j < accounts[i].size(); j++)
            {
                personWealth[i] += accounts[i][j];
            }
        }
        return *std::max_element(personWealth.begin(), personWealth.end());
    }
};

//int main(void)
//{
//
//
//}
