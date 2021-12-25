#include<iostream>
#include"LinkedList.h"
using namespace std;
class Solution {
public:
    
    ListNode* insertionSortList(ListNode* head)
    {
        
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* tmpHead = nullptr;
        ListNode* resultHead = tmpHead;
        while(head != nullptr)
        {
            tmpHead = resultHead;
            ListNode* prev = nullptr;
            while(tmpHead != nullptr && head->val > tmpHead->val )
            {
                prev = tmpHead;
                tmpHead = tmpHead->next;
            }
            ListNode* newNode = new ListNode(head->val);
            if(tmpHead == resultHead) // if inserted node to be in first place
            {
                ListNode* tmp = resultHead;
                resultHead = newNode;
                resultHead->next = tmp;
            }
            else
            {
                ListNode* next = prev->next;
                prev->next = newNode;
                newNode->next = next;
            }
            ListNode* tmp = head;
            head = head->next;
            delete(tmp);
        }
        return resultHead;
    }
};
//int main(void)
//{
//    int arr[] = {-1,5,3,4,0};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    ListNode* head = createList(arr,n);
//    Solution obj;
//    head = obj.insertionSortList(head);
//    printList(head);
//}