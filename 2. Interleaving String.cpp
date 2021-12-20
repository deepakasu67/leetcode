#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<int> charCount(26, 0);
        for(int i = 0 ; i < s1.length(); i++)
        {
            charCount[s1[i] - 'a']++;
        }

        for (int i = 0; i < s2.length(); i++)
        {
            charCount[s2[i] - 'a']++;
        }

        vector<int> charCountForS3(26, 0);
        for (int i = 0; i < s3.length(); i++)
        {
            charCountForS3[s3[i] - 'a']++;
        }

        for(int i = 0 ;i < 26; i++)
        {
            if(charCountForS3[i] != charCount[i])
            {
                return false;
            }
        }
        return true;
    }
};
//int main(void)
//{
//    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
//    Solution obj;
//    obj.isInterleave(s1, s2, s3);
//}