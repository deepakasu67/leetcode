#include<iostream>
#include"LinkedList.h"
using namespace std;
class Solution {
public:
    void reorderListutil(ListNode *&head, ListNode* currentEnd)
    {
        if(currentEnd || currentEnd->next == nullptr)
        {
            return;
        }
        reorderListutil(head, currentEnd->next);
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode* temp = currentEnd->next;
        currentEnd->next = nullptr;
        ListNode* next = head->next;
        head->next = temp;
        temp->next = next;
        head = next;
    }
    void reorderList(ListNode* head)
    {
        ListNode* temp = head;
        reorderListutil(temp, temp);
    }
};
//int main(void)
//{
//    int a[] = { 1 };
//    ListNode* root = createList(a, 1);
//    Solution obj;
//    obj.reorderList(root);
//} 