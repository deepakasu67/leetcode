#include<iostream>
#include"LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoListsUtil(ListNode* l1, ListNode* l2)
    {
      
        ListNode* root = nullptr;
        if(l1 == nullptr)
        {
            return l2;
        }
        if(l2 == nullptr)
        {
            return l1;
        }
        if(l1->val <= l2->val)
        {
            root = l1;
            root->next = mergeTwoListsUtil(l1->next, l2);
        }
        else
        {
            root = l2;
            root->next = mergeTwoListsUtil(l1, l2->next);
        }
        return root;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        return mergeTwoListsUtil(l1, l2);
    }
};
//
//int main(void)
//{
//    int l1[] = { 1,3,4,6};
//    int n1 = sizeof(l1) / sizeof(l1[0]);
//    ListNode *root1 = createList(l1, n1);
//
//    int l2[] = { 2,5,6 };
//    int n2 = sizeof(l2) / sizeof(l2[0]);
//    ListNode* root2 = createList(l2, n2);
//
//    Solution obj;
//    ListNode* mergedList = obj.mergeTwoLists(root1, root2);
//    printList(mergedList);
//}