#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        int sIdx = 0;
        string str;
        for (int i = 0; i < s.length(); i++)
        {
            if (i == spaces[sIdx])
            {
                str += " ";
                sIdx++;
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
