#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int expansionLength(int &left, int &right, string s)
    {
        int max1 = 0;
        while (left >= 0 && right < s.length())
        {
            if (s[left] != s[right])
                break;
            max1 += 2;
            left--, right++;
        }
        return max1;
    }
    string longestPalindrome(string s) 
    {
        if (s.length() == 1)
            return s;
        int longestPalindrom = 0;
        int left = 0, right = 0, left2 = 0;
        int mlPLeft = 0, mlPRight = 0;
        for (int i = 1; i < s.length(); i++)
        {
            int max1 = 1;
            int max2 = INT_MIN;
            if (s[i - 1] == s[i])
            {
                max2 = 2;
                left2 = i - 2;
                int right2 = i + 1;
                max2 += expansionLength(left2, right2, s);
            }
            
            {
                left = i - 1;
                right = i + 1;
            }
            max1 += expansionLength(left, right, s);
            max1 = max(max1, max2);
            if (max1 > longestPalindrom)
            {
                mlPLeft = max(min(left2,left)+1,0);
                longestPalindrom = max1;
                
            }
            left2 = left = INT_MAX;
        }
        return s.substr(mlPLeft, longestPalindrom);
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.longestPalindrome("jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel");
//}