#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n)
    {
        vector<int> generatedNumber;
        generatedNumber.push_back(0);
        generatedNumber.push_back(1);

        for(int i = 2; i <= n; i++)
        {
            int afterDivide = i / 2;
            if(i%2 == 0)
            {
                generatedNumber.push_back(generatedNumber[afterDivide]);
            }
            else
            {
                generatedNumber.push_back(generatedNumber[afterDivide] + generatedNumber[afterDivide + 1]);
            }
        }
        return *max_element(generatedNumber.begin(), generatedNumber.end());
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.getMaximumGenerated(7);
//}