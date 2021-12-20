#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
    {
        vector<int> hashTblContainsIdx(100,-1);
        for(int i = 0;i < arr.size(); i++)
        {
            hashTblContainsIdx[arr[i] - 1] = i;
        }
        for(int i = 0; i < pieces.size(); i++)
        {
            if(pieces[i].size() > 1)
            {
                int idx = hashTblContainsIdx[pieces[i][0] - 1];
                for(int j=0;j < pieces[i].size(); j++)
                {
                    if (hashTblContainsIdx[pieces[i][j] - 1] == -1 || 
                        hashTblContainsIdx[pieces[i][j] - 1] != idx)
                        return false;
                    idx++;
                }
            }
            else
            {
                if (hashTblContainsIdx[pieces[i][0] - 1] == -1)
                    return false;
            }
        }
        return true;
    }
};

//int main(void)
//{
//    vector<int> arr = { 1,3,5,7 };
//    vector<vector<int>> pieces = { {2,4,6,8 } };
//    Solution obj;
//    obj.canFormArray(arr, pieces);
//}