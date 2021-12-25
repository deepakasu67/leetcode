#include<iostream>
#include"LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumberUtil(ListNode* biggerList,
        ListNode* smallerList, 
        int diffSizeLength,
        int &carry)
    {
        if(biggerList == nullptr || smallerList == nullptr)
        {
            return nullptr;
        }
        ListNode* head = nullptr;
        if(diffSizeLength > 0)
            head = addTwoNumberUtil(biggerList->next, smallerList,diffSizeLength-1,carry);
        else
            head = addTwoNumberUtil(biggerList->next, smallerList->next, diffSizeLength, carry);
        int sum = 0;
        if(diffSizeLength == 0)
        {
            sum = smallerList->val + biggerList->val+ carry;
        }
        else
        {
            sum = biggerList->val + carry;
        }

        carry = (sum / 10) % 10;
        ListNode* node = new ListNode(sum % 10);
        node->next = head;
        head = node;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
        {
            return l2;
        }
        if(l2 == nullptr)
        {
            return l1;
        }
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int length1 = 0, length2 = 0;
        while(temp1 != nullptr)
        {
            length1++;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr)
        {
            length2++;
            temp2 = temp2->next;
        }

        ListNode* biggerList = nullptr;
        ListNode* smallerList = nullptr;
        if (length1 > length2)
        {
            biggerList = l1;
            smallerList = l2;
        }
        else
        {
            biggerList = l2;
            smallerList = l1;
        }
        int carry = 0;
        int diffInSize = abs(length1 - length2);

        ListNode* addedListHead = addTwoNumberUtil(biggerList, smallerList,diffInSize,carry);
        if(carry > 0)
        {
            ListNode* node = new ListNode(carry);
            node->next = addedListHead;
            addedListHead = node;
        }
        return addedListHead;
    }
};

//int main(void)
//{
//    Solution obj;
//    int arr1[] = {1,9,9,9,9};
//    int arr2[] = {1};
//    int n1 = sizeof(arr1) / sizeof(arr1[0]);
//    int n2 = sizeof(arr2) / sizeof(arr2[0]);
//    ListNode* root1 = createList(arr1,n1);
//    ListNode* root2 = createList(arr2, n2);
//    printList(obj.addTwoNumbers(root1, root2));
//}