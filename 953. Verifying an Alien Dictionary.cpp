#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        if (words.size() <= 1)
            return true;
        vector<int> charWithOrder(26);
        int i = 1;
        for (char element : order)
        {
            charWithOrder[(int)element - (int)'a'] = i;
            i++;
        }
        for(int j = 0 ; j < words.size() - 1; j++)
        {
            string word1 = words[j];
            string word2 = words[j + 1];
            int k = 0;
            for(; k < word1.length();k++)
            {
                if(k >= word2.length())
                {
                    return false;
                }
                if(charWithOrder[word1[k]-'a'] == charWithOrder[word2[k] - 'a'])
                {
                    continue;
                }
                if(charWithOrder[word1[k] - 'a'] < charWithOrder[word2[k] - 'a'])
                {
                    break;
                }
                else
                {
                    return false;
                }
            }
  
        }
        return true;
    }
};

//int main(void)
//{
//    vector<string> words = { "app","apple" };
//    string order = "abcdefghijklmnopqrstuvwxyz";
//    Solution obj;
//    cout<<obj.isAlienSorted(words, order);
//}