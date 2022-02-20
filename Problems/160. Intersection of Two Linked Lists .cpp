//
// Created by Deepak Sahu on 2/6/22.
//
#include <iostream>
#include "LinkedList.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getSizeOfLinkedList(ListNode *headA)
    {
        int sze = 0;

        while(headA != nullptr)
        {
            sze++;
            headA = headA->next;
        }
        return sze;
    }
    ListNode* advanceBySome(ListNode * head, int num)
    {
        while(num-- && head == nullptr)
        {
            head = head->next;
        }
        return head;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeOfA = getSizeOfLinkedList(headA);
        int sizeOfB = getSizeOfLinkedList(headB);
        ListNode* startA = nullptr;
        ListNode* startB = nullptr;
        if(sizeOfA > sizeOfB)
        {
            startA = advanceBySome(headA,sizeOfA - sizeOfB);
            startB = headB;
        }
        else
        {
            startB = advanceBySome(headB, sizeOfB - sizeOfA);
            startA = headA;
        }

        while(startA != nullptr && startB != nullptr)
        {
            if(startA == startB)
                return startA;
            startB = startB->next;
            startA = startA->next;
        }
        return nullptr;
    }
};

