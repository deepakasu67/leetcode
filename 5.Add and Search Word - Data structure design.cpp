#include<iostream>
#include<string>
#include<vector>
using namespace std;

class WordDictionary {
    WordDictionary* node[26];
    bool isEndNode;
    WordDictionary* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(nullptr),node()
    {
        isEndNode = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        if (root == nullptr)
        {
            root = new WordDictionary();
        }
        WordDictionary* current = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (current->node[word[i] - 'a'] == nullptr)
                current->node[word[i] - 'a'] = new WordDictionary();
            current = current->node[word[i] - 'a'];
        }
        current->isEndNode = true;
    }

    bool searchUtil(WordDictionary* root, string word, int idx)
    {
        if (root == nullptr)
            return false;
        if (idx == word.length() && root->isEndNode == true)
            return true;
        if (idx == word.length() && root->isEndNode == false)
            return false;

        if (word[idx] == '.')
        {
            bool flag = false;
            for (int i = 0; i < 26; i++)
            {
                if (searchUtil(root->node[i], word, idx + 1) == true)
                    return true;
            }
            return false;
        }
        else
        {
            if (root->node[word[idx] - 'a'] != nullptr)
                return searchUtil(root->node[word[idx] - 'a'], word, idx + 1);
            else
                return false;
        }
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        return searchUtil(root, word, 0);
    }
};


//int main(void)
//{
//    WordDictionary obj;
//    obj.addWord("at");
//    obj.addWord("and");
//    obj.addWord("an");
//    obj.addWord("add");
//    obj.search("a");
//    obj.search(".at");
//    obj.addWord("bat");
//    obj.search(".at");
//    obj.search("an.");
//    obj.search("a.d.");
//    obj.search("b.");
//    obj.search("a.d");
//    obj.search(".");
//
//}