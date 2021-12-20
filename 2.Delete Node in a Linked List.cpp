#include<iostream>
#include"LinkedList.h"
using namespace std;
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete(temp);
    }
};
//int main(void)
//{
//    int a[] = {4, 5, 1, 9};
//
//    ListNode* head = createList(a, 4);
//    ListNode* node = head->next->next;
//    Solution obj;
//    obj.deleteNode(head);
//}