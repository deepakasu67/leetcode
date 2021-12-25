#include<iostream>
#include<vector>
#include<algorithm>
#include "LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoSortedList(ListNode* a, ListNode* b)
    {
        if (a == nullptr)
        {
            return b;
        }
        if (b == nullptr)
        {
            return a;
        }
        ListNode* result = nullptr;
        if (a->val <= b->val)
        {
            result = a;
            result->next = mergeTwoSortedList(a->next, b);
        }
        else
        {
            result = b;
            result->next = mergeTwoSortedList(a, b->next);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        for_each(lists.begin(), lists.end(), [&result,this](ListNode* list)
                                                            {
                                                                 result = mergeTwoSortedList(result, list);
                                                            });
        return result;

    }
};
//int main(void)
//{
//    int arr[] = { 1,4,5 };
//    int arr1[] = { 1,3,4 };
//    int arr2[] = { 2,6 };
//    ListNode* head1= createList(arr,3);
//    ListNode* head2 = createList(arr1, 3);
//    ListNode* head3 = createList(arr1, 2);
//    vector<ListNode*> lists = { head1, head2, head3 };
//    cout << "list 1 :";
//    printList(head1);
//    cout << "\nlist 2 :";
//    printList(head2); 
//    cout << "\nlist 3 :";
//    printList(head3);
//    cout << "\nMerge List";
//    Solution obj;
//    ListNode* mergedList = obj.mergeKLists(lists);
//    printList(mergedList);
//
//}