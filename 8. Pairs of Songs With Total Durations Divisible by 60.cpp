#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        if (time.size() == 1)
            return 0;
        for(int i = 0; i < time.size(); i++)
        {
            time[i] = time[i] % 60;
        }
        vector<int> previousNumbers(60,0);
        int count = 0;
        for(int i = 0; i < time.size(); i++)
        {
            int nums =  previousNumbers[((60 - time[i]) % 60)];
            count += nums;
            previousNumbers[time[i]]++;
        }
        return count;
    }
};

//int main(void)
//{
//    vector<int> num{ 30,20,150,100,40 };
//    Solution obj;
//    cout<<obj.numPairsDivisibleBy60(num);
//}