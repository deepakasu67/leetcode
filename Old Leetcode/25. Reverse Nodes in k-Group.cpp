#include<iostream>
#include"LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* reverse(ListNode* head, int k, ListNode **headNext)
    {
        ListNode* current = head;
        ListNode* prev = NULL, * next = NULL;
        int j = k;
        while (current != nullptr && j--!=0)
        {
            current = current->next;
        }
        if (j > 0) // after j becomes zero and exits from the loop it is getting decrement to -1
        {
            return head;
        }

        current = head;
        while (current != NULL && k-- != 0) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
       
        head = prev;
        *headNext = next;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* temp = head;
        ListNode* headNext = nullptr;
        head = reverse(head, k, &headNext);
        if (head == temp && headNext == nullptr)
        {
            return head;
        }
        temp->next = reverseKGroup(headNext, k);
        return head;
    }
};
//int main(void)
//{
//    Solution obj;
//    int arr[] = { 1,2,3,4,5,6,7,8 };
//    ListNode* head = nullptr;
//    head = createList(arr, 8);
//    cout << "\nbefore swapping:";
//    printList(head);
//    head = obj.reverseKGroup(head, 1);
//    cout << "\n after swapping:";
//    printList(head);
//}