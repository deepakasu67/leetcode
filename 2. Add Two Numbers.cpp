#include "LinkedList.h"
#include<iostream>
using namespace std;

class Solution {
public:
	int addTwoNumbersUtils(ListNode* l1, ListNode* l2, ListNode **head)
	{

	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr;
		ListNode* tail = nullptr;
		int carry = 0;
		while (l1 || l2 || carry)
		{
			int sum = (l1 != nullptr ? l1->val : 0) +
					  (l2 != nullptr ? l2->val : 0 )+
					  carry;

			carry = sum >= 10 ? 1 : 0;
			int nodeValue = sum % 10;
			ListNode *tmp = new ListNode(nodeValue);
			if (!head)
			{
				head = tmp;
			}
			else
			{
				tail->next = tmp;
			}
			tail = tmp;
			l1 = (l1 != nullptr) ? l1->next : nullptr;
			l2 = (l2 != nullptr) ? l2->next : nullptr;
		}

		return head;
    }
};

//int main(void)
//{
//	struct ListNode* head1 = NULL;
//	struct ListNode* head2 = NULL;
//	
//	//push(&head1, 3);
//
//	push(&head2, 9);
//	push(&head2, 9);
//	push(&head2, 9);
//
//	printf("Given linked list1\n");
//	printList(head1);
//	printf("\nGiven linked list2\n");
//	printList(head2);
//	Solution obj;
//	cout << "\nSummed linked list\n";
//	printList(obj.addTwoNumbers(head1, head2));
//}
