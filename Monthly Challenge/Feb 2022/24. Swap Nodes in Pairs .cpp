//
// Created by Deepak Sahu on 2/15/22.
//
#include <iostream>
#include "LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
            return head;

        ListNode* temp = head;
        head = head->next;
        ListNode* next = head->next;
        head->next = temp;
        temp->next = swapPairs(next);
        return head;
    }
};



//int main(void)
//{
//    int arr[] = {1,2,3,4, 5};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    ListNode * head = createList(arr,n);
//
//    head = Solution().swapPairs(head);
//    printList(head);
//}