#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0;
        int j = num.size() - 1;
        while (i <= j)
        {
            if (i == j)
                return (num[i] == '0' || num[i] == '1' || num[i] == '8');
            if (num[i] == '6' && num[j] == '9')
            {
                i++;
                j--;
                continue;
            }
            else if (num[i] == '8' && num[j] == '8')
            {
                i++;
                j--;
                continue;
            }
            else if (num[i] == '1' && num[j] == '1')
            {
                i++;
                j--;
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.isStrobogrammatic("96");
//}