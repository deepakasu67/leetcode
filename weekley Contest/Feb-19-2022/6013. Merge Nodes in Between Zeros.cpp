//
// Created by Deepak Sahu on 2/19/22.
//
#include <iostream>
#include "LinkedList.h"
using namespace std;
class Solution {
public:
    ListNode* mergeNodes(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* tmpNode = head->next;
        int sum = 0;
        while(tmpNode != nullptr)
        {
            if( tmpNode->val == 0)
                break;
            sum += tmpNode->val;
            ListNode* tmp = tmpNode;
            tmpNode = tmpNode->next;
            delete(tmp);
        }
        delete(head);
        head = new ListNode(sum);
        head->next = mergeNodes(tmpNode);
        return head;
    }
};

//int main(void)
//{
//    int arr[] = {0,3,1,0,4,5,2,0};
//    int n = sizeof (arr)/sizeof (arr[0]);
//    ListNode* head = createList(arr, n);
//    printList(head);
//    head = Solution().mergeNodes(head);
//    cout<<endl;
//    printList(head);
//}
