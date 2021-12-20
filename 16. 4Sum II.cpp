#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        int result = 0;
        map<int,int> sumOfAandB;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < B.size(); j++)
            {
                if(sumOfAandB.find(A[i] + B[j]) == sumOfAandB.end())
                {
                    sumOfAandB.insert(make_pair((A[i] + B[j]), 1));
                }
                else
                {
                    sumOfAandB[(A[i] + B[j])]++;
                }
            }
        }
        for (int i = 0; i < C.size(); i++)
        {
            for (int j = 0; j < D.size(); j++)
            {
                int findInD = 0 - (C[i] + D[j]);
                result += sumOfAandB[findInD];
            }
        }
        return result;
    }
};
//[0, 1, -1]
//[-1, 1, 0]
//[0, 0, 1]
//[-1, 1, 1]
//int main(void)
//{
//    vector<int> A = { 0, 1, -1 };
//    vector<int> B = { -1, 1, 0 };
//    vector<int> C = { 0, 0, 1 };
//    vector<int> D = { -1, 1, 1 };
//    Solution obj;
//    obj.fourSumCount(A, B, C, D);
//}