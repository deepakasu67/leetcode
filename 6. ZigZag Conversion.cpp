#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows < 2)
            return s;
        string ans;
        int steps = 2 * numRows - 2;
        int stepsUp = 0;
        for (int i = 0; i < s.length() && steps > 0; i++)
        {
            for (int j = i; j < s.length(); j += steps)
            {
                ans.push_back(s[j]);

                
                if (i!=0 && j!=i)
                {
                    if (j + stepsUp >= s.length())
                        break;
                    j = j + stepsUp;
                    ans.push_back(s[j]);
                }
            }
            steps -= 2;
            stepsUp+= 2;
        }
        steps = 2 * numRows - 2;
        for (int i = numRows - 1; i < s.length(); i += steps)
            ans.push_back(s[i]);

        return ans;
    }
};
//int main(void)
//{
//    Solution obj;
//    cout<<"PINALSIGYAHRPI : "<<obj.convert("PAYPALISHIRING", 4)<<endl;
//    cout<<"PAHNAPLSIIGYIR : "<<obj.convert("PAYPALISHIRING", 3)<<endl;
//    cout<<"A : "<<obj.convert("A", 1)<<endl;
//    cout<<"ABCDE : "<<obj.convert("ABCDE", 4)<<endl;
//}