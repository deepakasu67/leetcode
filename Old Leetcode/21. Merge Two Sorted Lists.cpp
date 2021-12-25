//https://leetcode.com/problems/merge-two-sorted-lists/
#include "LinkedList.h"
#include<iostream>

class Solution {
public:
	struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		if (l1->val <= l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode dummy(INT_MIN);
//		ListNode* tail = &dummy;
//
//		while (l1 && l2) {
//			if (l1->val < l2->val) {
//				tail->next = l1;
//				l1 = l1->next;
//			}
//			else {
//				tail->next = l2;
//				l2 = l2->next;
//			}
//			tail = tail->next;
//		}
//
//		tail->next = l1 ? l1 : l2;
//		return dummy.next;
//	}
//};
//int main()
//{
//	/* Start with the empty list */
//	struct ListNode* head1 = NULL;
//	struct ListNode* head2 = NULL;
//	push(&head1, 5);
//	push(&head1, 4);
//	push(&head1, 2);
//	push(&head1, 1);
//	push(&head2, 4);
//	push(&head2, 3);
//	push(&head2, 1);
//
//	printf("Given linked list1\n");
//	printList(head1);
//	printf("\nGiven linked list2\n");
//	printList(head2);
//	Solution obj;
//	ListNode *mergeListhead = obj.mergeTwoLists(head1, head2);
//	printf("\nmerged linked list\n");
//	printList(mergeListhead);
//	return 0;
//}