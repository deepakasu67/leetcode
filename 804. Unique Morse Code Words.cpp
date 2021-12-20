/*
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation:
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
*/


#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> moresChar = { ".-","-...","-.-.","-..","."
                                    ,"..-.","--.","....","..",".---",
                                    "-.-",".-..","--","-.","---",".--.",
                                    "--.-",".-.","...","-","..-","...-",
                                    ".--","-..-","-.--","--.." };
        int size = words.size();
        set<int> sets;
        int output = 0;
        vector<string> transform(size);
        for (int j = 0;j < size; j++)
        {
            string word = words[j];
            int encodedNumber = 0;
            for (int i = 0; i < word.length();i++)
            {
                transform[j] += moresChar[word[i] - 'a'];
            }
            for (int i = 0; i < transform[j].length();i++)
            {
                if (transform[j][i] == '.')
                {
                    encodedNumber += 0;
                }
                else if (transform[j][i] == '-')
                {
                    encodedNumber += 1 * (1 << i);
                }
            }
            sets.insert(encodedNumber);

        }
        return sets.size();
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<string> words = { "gin", "zen", "gig", "msg" } ;
//    cout<<obj.uniqueMorseRepresentations(words);
//    cout << obj.uniqueMorseRepresentations(words);
//}