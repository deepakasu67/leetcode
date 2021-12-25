#include<iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    Node* first = nullptr;
    Node* last = nullptr;
    void treeToDoublyListUtil(Node* root)
    {
        if (root == nullptr)
            return;

        treeToDoublyListUtil(root->left);
        if(first == nullptr)
        {
            first = root;
        }
        else
        {
            root->left = last;
            last->right = root;
        }
        last = root;
        treeToDoublyListUtil(root->right);
    }
    Node* treeToDoublyList(Node* root)
    {
        if (root == nullptr)
            return nullptr;

        treeToDoublyListUtil(root);
        first->left = last;
        last->right = first;
        return first;
    }
};

//int main(void)
//{
//    Node* root = new Node(4);
//    root->left = new Node(2);
//    root->right= new Node(5);
//    root->left->left = new Node(1);
//    root->left->right = new Node(3);
//    Solution obj;
//    obj.treeToDoublyList(root);
//}