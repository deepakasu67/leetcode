#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if(head == nullptr)
        {
            return head;
        }
        Node* tmpHead = head;
        while(tmpHead != nullptr)
        {
            Node* newNode = new Node(tmpHead->val);
            newNode->next = tmpHead->next;
            tmpHead->next = newNode;
            tmpHead = newNode->next;
        }
        tmpHead = head;

        //setting RandomPointer
        while( tmpHead != nullptr && tmpHead->next != nullptr)
        {
            if(tmpHead->random != nullptr)
                tmpHead->next->random = tmpHead->random->next;
            else
                tmpHead->next->random = nullptr;
            tmpHead = tmpHead->next->next;
        }

        //segregating the List
        tmpHead = head;
        Node* resultHead = tmpHead->next;
        Node* result = resultHead;
        while (tmpHead != nullptr && tmpHead->next != nullptr)
        {
            tmpHead->next = tmpHead->next->next;
            if(resultHead != nullptr && resultHead->next != nullptr)
                resultHead->next = resultHead->next->next;
            resultHead = resultHead->next;
            tmpHead = tmpHead->next;
        }
        return result;
    }
};
//
//int main(void)
//{
//    Node* node7 = new Node(7);
//    Node* node13 = new Node(13);
//    Node* node11 = new Node(11);
//    Node* node10 = new Node(10);
//    Node* node1 = new Node(1);
//
//    node7->next = node13;
//    node7->random = nullptr;
//    node13->next = node11;
//    node13->random = node7;
//
//    node11->next = node10;
//    node11->random = node1;
//
//    node10->next = node1;
//    node10->random = node11;
//
//    node1->next = nullptr;
//    node1->random = node7;
//
//    Solution().copyRandomList(node7);
//
//}
