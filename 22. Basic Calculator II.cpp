#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int operatOnTwoNumber(string& first, string& second, char operatr)
    {
        switch (operatr)
        {
        case '+':
            return stol(first) + stol(second);
        case '-':                   
            return stol(first) - stol(second);
        case '/':                   
            return stol(first) / stol(second);
        case '*':                   
            return stol(first) * stol(second);;
        default:
            return 0;
        }
    }
    bool doesItHaveOper(char ch)
    {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }
    void manipulateString(string& s, int& i, char operation, string& first, string& second)
    {
        if (s[i] == '/' || s[i] == '*')
        {
            int firstStartIdx = i - first.length();
            i++;
            second.clear();
            while (i < s.size() && !doesItHaveOper(s[i]))
            {
                second += s[i];
                i++;
            }
            string afterOperation = to_string(operatOnTwoNumber(first, second, operation));
            s.replace(firstStartIdx, (i - 1) - firstStartIdx + 1, afterOperation);
            i = firstStartIdx ? firstStartIdx - 1 : 0;
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            int firstStartIdx = i - first.length() - 1;
            firstStartIdx = firstStartIdx < 0 ? 0 : firstStartIdx;
            string ch = (firstStartIdx == 0 ? "+1" : string(1, s[firstStartIdx]) + '1');
            first = to_string(operatOnTwoNumber(ch,first,'*'));
            i++;
            while (i < s.size() && !doesItHaveOper(s[i]))
            {
                second += s[i];
                i++;
            }
            int opertionOnNumber = operatOnTwoNumber(first, second, operation);
            string afterOperation = to_string(opertionOnNumber);
            if(opertionOnNumber >= 0)
            {
                afterOperation = '+' + to_string(opertionOnNumber);
            }

            s.replace(firstStartIdx, (i - 1) - firstStartIdx + 1, afterOperation);
            i = 0;
        }
        first.clear();
        second.clear();
        return;
    }
    int calculate(string s)
    {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        //first do divide operation
        string first, second;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '/')
                manipulateString(s, i, '/', first, second);
            if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                first.clear();
                i++;
            }
            first += s[i];
        }
        //multiplication operation
        first.clear(), second.clear();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
                manipulateString(s, i, '*', first, second);
            if (s[i] == '+' || s[i] == '-' || s[i] == '/')
            {
                first.clear();
                i++;
            }
            first += s[i];
        }
        //addition
        first.clear(), second.clear();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+')
                manipulateString(s, i, '+', first, second);
            if (s[i] == '*' || s[i] == '-' || s[i] == '/')
            {
                first.clear();
                i++;
            }
            first += s[i];
        }
        //subtraction
        first.clear(), second.clear();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
                manipulateString(s, i, '-', first, second);
            if (s[i] == '*' || s[i] == '+' || s[i] == '/')
            {
                first.clear();
                i++;
            }
            first += s[i];
        }
        return stoi(s);
    }
};
//
//int main(void)
//{
//    string expr = "1*2+3*4-5*6+7*8-9*10";
//    Solution obj;
//    obj.calculate(expr);
//}