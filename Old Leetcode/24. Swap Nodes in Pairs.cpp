#include<iostream>
#include"LinkedList.h"
using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* temp = head;
        head = head->next;
        ListNode* headNext = head->next;

        head->next = temp;
        temp->next = swapPairs(headNext);
        return head;
    }
};
//int main(void)
//{
//    Solution obj;
//    int arr[] = { 1,2,3,4,5 };
//    ListNode* head = createList(arr, 0);
//    cout << "\nlist before swapping";
//    printList(head);
//    head = obj.swapPairs(head);
//    cout << "\nlist after swapping";
//    printList(head);
//
//}
