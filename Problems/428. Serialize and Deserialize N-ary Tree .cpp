//
// Created by Deepak Sahu on 12/26/21.
//
#include <iostream>
#include<vector>
#include <string>
#include<stack>
using namespace  std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
//    int idx = 0;
public:
    // Encodes a tree to a single string.
    string serialize(Node* root)
    {
        string str = "[";
        str += to_string(root->val);

        for(int i =0; i < root->children.size() ; i++)
        {
            str += serialize(root->children[i]);
        }
        str += ']';
        return str;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string &data)
    {
        int idx = 0;
        stack<Node*> st;
        string accumulator ;
        Node* root = nullptr;
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i] == '[')
            {
                int idx =  find_if(data.begin() + i + 1, data.end(), [&](char ch){
                    return (ch == '[' || ch == ']');
                }) - data.begin();
                string num = data.substr(i+1,idx - 1);
                Node *node = new Node(atoi(num.c_str()));
                st.push(node);
                i = idx - 1;
            }
            if(!st.empty() && data[i] == ']')
            {
                Node* node = st.top();
                st.pop();
                if(!st.empty()) {
                    root = st.top();
                    st.top()->children.push_back(node);
                }
                else
                    root = node;

            }
        }
        return root;
    }
};

//int main(void)
//{
//    Node* n1 = new Node(1);
//    Node* n2 = new Node(2);
//    Node* n3 = new Node(3);
//    Node* n4 = new Node(4);
//    Node* n5 = new Node(5);
//    Node* n6 = new Node(6);
//
//    n1->children =  {n3,n2,n4};
//    n3->children = {n5,n6};
//
//    string str = Codec().serialize(n1);
//    cout<<str<<endl;
//    Node* root = Codec().deserialize(str);
//    cout<<Codec().serialize(root);
//}