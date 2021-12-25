#include<iostream>
#include"LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr)
            return head;

        ListNode *tempIt = head;
        ListNode* tail = nullptr;
        while (tempIt)
        {
            if (tail)
            {
                if (tail->val == tempIt->val)
                {
                    ListNode* tempNode = tempIt;
                    tempIt = tempIt->next;
                    tail->next = tempNode->next;
                    delete(tempNode);
                    continue;
                }
            }
            tail = tempIt;
            tempIt = tempIt->next;
        }
        return head;
    }
};
//int main(void)
//{
//    int nums[] = { 1,2,3,3,4,5 };
//    int n = sizeof(nums) / sizeof(nums[0]);
//    Solution obj;
//    ListNode* head = createList(nums, n);
//    obj.deleteDuplicates(head);
//    printList(head);
//} 