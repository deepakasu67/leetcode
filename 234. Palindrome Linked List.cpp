#include<iostream>
#include"LinkedList.h"
using namespace std;
class Solution {
public:
    void isPalindromUtil(ListNode** head, ListNode* endNode, bool &isPalindrom, bool &isPassed)
    {
        if (!endNode)
        {
            return;
        }
        isPalindromUtil(head, endNode->next, isPalindrom, isPassed);
        if (isPassed || isPalindrom == false)
        {
            return;
        }
        if (*head == endNode)
        {
            isPassed = true;
            return;
        }
        if ((*head)->val != endNode->val)
        {
            isPalindrom = false;
        }
        if ((*head)->next == endNode)
        {
            isPassed = true;
            return;
        }
        (*head) = (*head)->next;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
        {
            return true;
        }
        if (head->next == nullptr)
        {
            return true;
        }
        ListNode* tmpHead = head;
        bool isPalindrome = true;
        bool isPassed = false;
        isPalindromUtil(&tmpHead, head,isPalindrome, isPassed);
        return isPalindrome;
    }
};

//int main(void)
//{
//    Solution obj;
//    ListNode* head = nullptr;
//    //1 2 4 3 2 1
//    push(&head, 1);
//    push(&head, 2);
//    push(&head, 3);
//    push(&head, 4);
//    push(&head, 2);
//    push(&head, 1);
//
//    cout << "\List:";
//    printList(head);
//    cout<<obj.isPalindrome(head);
//}