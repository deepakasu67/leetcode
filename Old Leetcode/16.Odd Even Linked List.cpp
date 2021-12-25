#include<iostream>
#include"LinkedList.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ListNode* evenListhead = nullptr, *eventail = nullptr;
        ListNode* oddListHead = head, * oddListTail = nullptr;
        while (head != nullptr && head->next != nullptr)
        {
            ListNode* nextNext = head->next->next;
            if (evenListhead == nullptr)
            {
                evenListhead = head->next;
                eventail = head->next;
            }
            else
            {
                eventail->next = head->next;
                eventail = eventail->next;
            }
            head->next = nextNext;
            if (head->next == nullptr)
            {
                oddListTail = head;
            }
            head = head->next;
            
            eventail->next = nullptr;
        }
        if (oddListTail != nullptr)
        {
            oddListTail->next = evenListhead;
        }
        else if(head !=nullptr)
        {
            head->next = evenListhead;
        }

        return oddListHead;

    }
};
//int main(void)
//{
//    ListNode* head = createList(nullptr,0);
//    Solution obj;
//    obj.oddEvenList(head);
//}