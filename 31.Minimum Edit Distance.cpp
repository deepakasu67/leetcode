#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dpArray(word1.size() + 1, vector<int>(word2.size() + 1, 0 ));
        for (int i = 0; i < dpArray.size(); i++)
        {
            dpArray[i][0] = i;
        }
        for (int i = 0; i < dpArray[0].size(); i++)
        {
            dpArray[0][i] = i;
        }
        for (int i = 1; i < dpArray.size(); i++)
        {
            for (int j = 1; j < dpArray[0].size(); j++)
            {
                if (word1[i - 1 ] == word2[j - 1])
                {
                    dpArray[i][j] = dpArray[i - 1][j - 1];
                }
                else
                {
                    dpArray[i][j] = 1 + min(min(dpArray[i-1][j-1], //replace
                                            dpArray[i - 1][j]), //insert
                                            dpArray[i][j-1]); //delete
                }
            }
        }
        return dpArray[dpArray.size() - 1][dpArray[0].size() - 1];

    }
};
//int main(void)
//{
//    Solution obj;
//   cout<< obj.minDistance("horse", "ros");
//}