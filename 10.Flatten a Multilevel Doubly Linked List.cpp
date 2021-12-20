#include<iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    Node(int val) : val(val)
    {}
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    Node* lastChildNode = nullptr;
public:
    Node* flattenUtil(Node* head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->child != nullptr)
        {
            Node* child = flattenUtil(head->child);
            Node* next = head->next;
            head->next = child;
            child->prev = head;
            head->child = nullptr;
            lastChildNode->next = next;
            if (next != nullptr)
                next->prev = lastChildNode;
            flattenUtil(lastChildNode->next); // after attaching the childLinkedList we dont have to go head->next,
                                       //we can directly jump to nxt of last node of child linked list 
        }
        flattenUtil(head->next);
        if (head->next == nullptr)
            lastChildNode = head;

        return head;
    }
    Node* flatten(Node* head)
    {
        return flattenUtil(head);
    }
};

//int main(void)
//{
//    /*
//    1-- - 2-- - 3-- - 4-- - 5-- - 6--NULL
//        |
//        7-- - 8-- - 9-- - 10--NULL
//        |
//        11--12--NULL
//    */
//
//    //1st level DLL
//    Node* root = new Node(1);
//    root->prev = nullptr;
//    Node* two = new Node(2);
//    root->next = two;
//    two->prev = root;
//    Node* three = new Node(3);
//    two->next = three;
//    three->prev = two;
//    Node* four = new Node(4);
//    three->next = four;
//    four->prev = three;
//    Node* five = new Node(5);
//    four->next = five;
//    five->prev = four;
//    Node* six = new Node(6);
//    five->next = six;
//    six->prev = five;
//    six->next = nullptr;
//
//    //2nd level DLL
//    Node* secLevelRoot = new Node(7);
//    secLevelRoot->prev = nullptr;
//    Node* eight = new Node(8);
//    secLevelRoot->next = eight;
//    eight->prev = secLevelRoot;
//    Node* nine = new Node(9);
//    eight->next = nine;
//    nine->prev = eight;
//    Node* ten = new Node(10);
//    nine->next = ten;
//    ten->prev = nine;
//    ten->next = nullptr;
//
//    //3level Dll
//    Node* eleven = new Node(11);
//    eleven->prev = nullptr;
//    Node* tweleve = new Node(12);
//    eleven->next = tweleve;
//    tweleve->prev = eleven;
//    tweleve->next = nullptr;
//
//    //create Multilevel DLL
//    three->child = secLevelRoot;
//    eight->child = eleven;
//
//    /* 1---2---NULL
//       |
//       3-- - NULL*/
//    Node* root1 = new Node(1);
//    root1->prev = nullptr;
//    Node* two1 = new Node(2);
//    root1->next = two;
//    two->prev = root1;
//    two->next = nullptr;
//    Node* three1 = new Node(3);
//    three1->next = nullptr;
//    three1->prev = nullptr;
//    root1->child = three1;
//    Solution obj;
//    obj.flatten(root1);
//}