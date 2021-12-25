#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void permute(vector<int>& digits, int idx, int numberFormed, int countOfDig, vector<int> &ans)
    {
        if (countOfDig > 3)
            return ;
        
        if (countOfDig == 3 && (numberFormed % 10)%2 == 0 )
            ans.push_back(numberFormed);
        
        for (int i = 0; i < digits.size(); i++)
        {

        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        return {};
    }
};

//int main(void)
//{
//
//}
