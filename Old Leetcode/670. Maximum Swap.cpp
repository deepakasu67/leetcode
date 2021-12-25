#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num)
    {
        string strNum = to_string(num);
        int n = strNum.size();
        vector<int> maxEltIdxTillNow(n);
        maxEltIdxTillNow[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int prevIdx = maxEltIdxTillNow[i + 1];
            if (strNum[i] - '0' > strNum[prevIdx] - '0')
            {
                maxEltIdxTillNow[i] = i;
            }
            else
            {
                maxEltIdxTillNow[i] = prevIdx;
            }
        }
        for (int i = 0; i < strNum.size(); i++)
        {
            int maxTillNow = maxEltIdxTillNow[i];
            if (strNum[i] - '0' < strNum[maxTillNow] - '0')
            {
                swap(strNum[i], strNum[maxTillNow]);
                break;
            }
        }
        return atoi(strNum.c_str());
    }
};
//
//int main(void)
//{
//    Solution obj;
//    cout<<obj.maximumSwap(10909091);
//}