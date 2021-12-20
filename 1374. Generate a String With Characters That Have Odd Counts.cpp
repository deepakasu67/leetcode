#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        if (n & 1)
        {
            string s(n, 'a');
            return s;
        }
        else
        {
            string s(n - 1, 'a');
            s += 'b';
            return s;
        }

    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.generateTheString(7);
//}