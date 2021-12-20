#include<iostream>
#include"LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* resultHead = nullptr;
        ListNode* end = nullptr;
        int carry = 0;
        int result = 0;
        while(l1 || l2)
        {
            result = carry;
            if(l1)
            {
                result += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                result += l2->val;
                l2 = l2->next;
            }
            carry = (result / 10) % 10;
            if (end == nullptr)
            {
                end = new ListNode(result % 10);
            }
            else
            {
                end->next = new ListNode(result % 10);
                end = end->next;
            }
            if(resultHead == nullptr)
            {
                resultHead = end;
            }
        }
        if(carry)
        {
            end->next = new ListNode(carry);
        }
        return resultHead;
    }
};

//int main(void)
//{
//    int arr[] = { 9,9,9,9,9,9,9 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    ListNode* head = createList(arr, n);
//
//    int arr1[] = { 9,9,9,9 };
//    int n1 = sizeof(arr1) / sizeof(arr[0]);
//    ListNode* head1 = createList(arr1, n1);
//    Solution obj;
//    printList(obj.addTwoNumbers(head, head1));
//}
