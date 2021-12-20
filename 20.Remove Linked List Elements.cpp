#include<iostream>
#include"LinkedList.h"
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode* tempHead = head, *prev = nullptr;

        while(tempHead != nullptr)
        {
            ListNode* next = tempHead->next;
            if(tempHead->val == val)
            {
                if(head == tempHead)
                {
                    head = head->next;
                    delete(tempHead);
                }
                else
                {
                    delete(tempHead);
                    prev->next = next;
                }
            }
            else
                prev = tempHead;
            tempHead = next;
        }
        return head;
    }
};
//int main(void)
//{
//    Solution obj;
//    int a[] = {1,2,2,1};
//    ListNode* head = createList(a, 4);
//    obj.removeElements(head, 2);
//}