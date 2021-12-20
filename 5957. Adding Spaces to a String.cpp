#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        int s = 0;
        string str;
        for (int i = 0; i < s.length(); i++)
        {
            if (i == spaces[s])
            {
                str += " ";
                s++;
            }
            str += s[i];
        }
        return str;
    }
};

//int main()
//{
//    string s = "icodeinpython";
//    vector<int> spaces = { 1,5,7,9 };
//    Solution().addSpaces(s, spaces);
//}