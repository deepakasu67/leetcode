#include<iostream>
#include"LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEndUtil(ListNode* head, ListNode* prev, int &n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        removeNthFromEndUtil(head->next,head, n);
        n--;
        if (n == 0)
        {
            ListNode* tmp = head;
            if (prev == nullptr) // this means we are deleting head
            {
                head = head->next;
            }
            else
                prev->next = head->next;
            delete(tmp);
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* newHead = removeNthFromEndUtil(head, nullptr,n);
        return newHead;
    }
};
//int main(void)
//{
//    Solution obj;
//    ListNode* head = nullptr;
//    //1->2->3->4->5
//    push(&head, 5);
//    push(&head, 4);
//    push(&head, 3);
//    push(&head, 2);
//    push(&head, 1);
//    cout << "\nbefore deletion:\n";
//    printList(head);
//    int n = 5;
//    head =obj.removeNthFromEnd(head,n);
//    cout << "\nafter deletion:";
//    printList(head);
//}