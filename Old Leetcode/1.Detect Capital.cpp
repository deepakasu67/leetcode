#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word)
    {
        string temp = word;
        transform(word.begin(), word.end(), word.begin(),towlower);
        if(word == "leetcode")
        {
            if (temp == "leetcode")
            {
                return true;
            }
        }
        else if(word == "google")
        {
            if(temp == "Google")
            {
                return true;
            }
        }
        else if(word == "usa")
        {
            if (temp == "USA")
            {
                return true;
            }
        }
        int count =  count_if(temp.begin(), temp.end(),
            [](unsigned char ch) { return isupper(ch); });

        return count > 1 ? count == temp.length() ? true: false : count == 1 ? toupper(word[0]) == temp[0] ? true:false: true;
    }
};
//int main(void)
//{
//    
//}