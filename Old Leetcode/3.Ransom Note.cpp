/*
Given an arbitrary ransom note stringand another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomeNoteLen = ransomNote.length();
        int magazineLen = magazine.length();
        if (ransomeNoteLen > magazineLen)
        {
            return false;
        }
        int countRansomNoteChar[26] = { 0 };
        int countMagazineChar[26] = { 0 };
        for (int i = 0, j = 0;i < ransomeNoteLen || j < magazineLen; i++, j++)
        {
            if (i < ransomeNoteLen)
            {
                countRansomNoteChar[(int)ransomNote[i] - 'a']++;
            }
            if (j < magazineLen)
            {
                countMagazineChar[(int)magazine[j] - 'a']++;
            }
        }
        string distinctString = string(ransomNote.begin(),unique(ransomNote.begin(), ransomNote.end()));

        for (int i = 0; i < distinctString.length(); i++)
        {
            if (countRansomNoteChar[(int)distinctString[i] - 'a'] > countMagazineChar[(int)distinctString[i] - 'a'])
            {
                return false;
            }
        }
        return true;

    }
};
//int main(void){
//    Solution obj;
//    obj.canConstruct("bg",
//        "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj");
//}