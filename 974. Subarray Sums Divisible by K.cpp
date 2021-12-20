#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int result = 0;
        for(int  win = 1; win <= A.size();win++)
        {
            for(int j = 0; j < A.size() - win + 1; j++)
            {
                int parSum = accumulate(A.begin() + j, A.begin() + j+win, 0);
                if (parSum % K == 0)
                    result++;
            }
        }
        return result;
    }
};
//int main(void)
//{
//    vector<int> list = { 4,5,0,-2,-3,1 };
//    Solution obj;
//    obj.subarraysDivByK(list, 5);
//}