#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class StreamChecker {
    StreamChecker* node[26];
    bool isEndNode;
    StreamChecker* root;
    deque<char> prevQueries;
public:
    /** Adds a word into the data structure. */
    void addWord(string& word)
    {
        if (root == nullptr)
        {
            root = new StreamChecker();
        }
        StreamChecker* current1 = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (current1->node[word[i] - 'a'] == nullptr)
                current1->node[word[i] - 'a'] = new StreamChecker();
            current1 = current1->node[word[i] - 'a'];
        }
        current1->isEndNode = true;
    }
    StreamChecker() : node(), isEndNode(false)
    {

    }

    StreamChecker(vector<string>& words)
    {
        root = (nullptr);
        StreamChecker();
        for (string str : words)
        {
            reverse(str.begin(), str.end());
            addWord(str);
        }
    }

    bool query(char letter)
    {
        prevQueries.push_front(letter);//if we use string then it will be memory limit exceeded as +operator will return newly constructed string
        if (root == nullptr)
            return false;
        StreamChecker* current = root;
        for (char c : prevQueries)
        {
            if (current->isEndNode == true)
                return true;
            if (current->node[c - 'a'] == nullptr)return false;

            current = current->node[c - 'a'];
        }
        return current->isEndNode;
    }
};
//int main(void)
//{
//    vector<string> words = { "baa","aa","aaaa","abbbb","aba" };
//    StreamChecker streamChecker(words); // init the dictionary.
//    streamChecker.query('a') == 1 ? cout<<"True" : cout<<"false";          
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";       
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";         
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('b') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//    streamChecker.query('a') == 1 ? cout<<",True" : cout<<",false";
//}