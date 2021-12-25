#include<iostream>
#include"LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (head == nullptr)
        {
            return head;
        }
        int temp = k;
        ListNode* tempHead = head;
        int size = 0;
        bool greaterSize = false;
        while (tempHead)
        {
            size++;
            if (size >= k)
            {
                greaterSize = true;
                break;
            }
            tempHead = tempHead->next;
        }
        if (greaterSize == false)
        {
            return head;
        }
        ListNode* lastNode = head;
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        while (current && temp--)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;

        lastNode->next = reverseKGroup(current, k);
        return head;
    }
};

//int main(void)
//{
//    int arr[] = { 1,2,3,4,5,6,7,8 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    ListNode* head = createList(arr, size);
//    Solution obj;
//    head = obj.reverseKGroup(head, 3);
//    printList(head);
//}