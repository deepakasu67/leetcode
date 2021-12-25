#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    vector<string> result;
public:
    string stringToBeInserted(int num)
    {
        if (num % 3 == 0 && num % 5 == 0)
        {
            return "FizzBuzz";
        }
        else if (num % 3 == 0)
        {
            return "Fizz";
        }
        else if (num % 5 == 0)
        {
            return "Buzz";
        }
        else
            return to_string(num);
    }
    vector<string> fizzBuzz(int n)
    {
        result.resize(n);
        for(int  i =0; i < n ; i++)
        {
            result[i] = stringToBeInserted(i + 1);
        }
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.fizzBuzz(15);
//}