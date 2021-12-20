#include<iostream>
#include<queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        int n = 0;
        while (!q.empty())
        {
            n = q.size();
            Node* curr = nullptr;
            Node* prev = nullptr;
            while (n != 0)
            {

                curr = q.front();
                if (prev != nullptr)
                {
                    prev->next = curr;
                }
                prev = curr;
                cout << curr->val;
                if (curr != nullptr && curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if (curr != nullptr && curr->right != nullptr)
                {
                    q.push(curr->right);
                }
                q.pop();
                n--;
            }
        }
        return root;
    }
};
//int main(void)
//{
//    Solution obj;
//    Node* root = new Node(1);
//    root->left = new Node(2);
//    root->right = new Node(3);
//    root->left->left = new Node(4);
//    root->left->right = new Node(5);
//    root->right->left = new Node(6);
//    root->right->right = new Node(7);
//    obj.connect(root);
//}
