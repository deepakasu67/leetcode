//
// Created by Deepak Sahu on 1/8/22.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix)
    {
        int maximum = INT_MIN;
        for(int i =0;i < matrix.size(); i++)
        {
            for(int j =0;j < matrix[i].size(); j++)
            {
                maximum = max(maximum,matrix[i][j]);
            }
        }


        for(int i =0;i < matrix.size(); i++)
        {
            vector<bool> isAllpresent(maximum, false);
            for(int j =0;j < matrix[i].size(); j++)
            {
                if(matrix[i][j] <= maximum)
                {
                    if(isAllpresent[matrix[i][j] -1] == true)
                        return false;
                    isAllpresent[matrix[i][j] -1] = true;
                }
                else
                    return false;
            }

            for(int i =0;i < isAllpresent.size(); i++)
            {
                if(isAllpresent[i] == false)
                {
                    return false;
                }
            }
        }

        for(int i =0;i < matrix.size(); i++)
        {
            vector<bool> isAllpresent(maximum, false);
            for(int j =0;j < matrix[i].size(); j++)
            {
                if(matrix[j][i] <= maximum)
                {
                    if(isAllpresent[matrix[j][i] -1] == true)
                        return false;
                    isAllpresent[matrix[j][i] -1] = true;
                }
                else
                    return false;
            }

            for(int i =0;i < isAllpresent.size(); i++)
            {
                if(isAllpresent[i] == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//int main(void)
//{
//   vector<vector<int>> matrix = {{1,2,3},{3,1,2},{2,3,1}};
//    //vector<vector<int>> matrix = {{1,1,1},{1,2,3},{1,2,3}};
//    Solution().checkValid(matrix);
//}

