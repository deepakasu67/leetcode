#include<iostream>
#include<string>
using namespace std;


class Trie {
    Trie* node[26];
    bool isEndNode;
    Trie* root;
public:
    /** Initialize your data structure here. */
    Trie():root(nullptr),node() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        isEndNode = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty())
        {
            return;
        }
        int i = 0;
        if (!root)
        {
            root = new Trie();
            root->node[word[i] - 'a'] = new Trie();
        }
        Trie* current = root;
        for (; i < word.length(); i++)
        {
            if (current->node[word[i] - 'a'] == NULL)
                current->node[word[i] - 'a'] = new Trie();

            current = current->node[word[i] - 'a'];
        }
        current->isEndNode = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (root == NULL)
            return false;
        Trie* current = root;
        for (int i = 0; i < word.length(); i++)
        {
            if ( current != NULL && current->node[word[i] - 'a'] == NULL)
            {
                return false;
            }
            current = current->node[word[i] - 'a'];
        }
        if (current->isEndNode == true)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        if (root == NULL)
            return false;
        Trie* current = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (current != NULL && current->node[word[i] - 'a'] == NULL)
            {
                return false;
            }
            current = current->node[word[i] - 'a'];
        }
        return true;
    }
};
//
//int main(void)
//{
//    Trie trie;
//
//    trie.insert("apple");
//    cout<<endl<<trie.search("apple");   // returns true
//    cout << endl << trie.search("app");     // returns false
//    cout << endl << trie.startsWith("app"); // returns true
//    trie.insert("app");
//    cout << endl << trie.search("app");     // returns true
//
//}