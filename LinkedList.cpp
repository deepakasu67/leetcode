#include "LinkedList.h"

/* Function to push a node */
ListNode* createList(int* arr, int n)
{
    ListNode* head = NULL;
    ListNode* p = new ListNode();

    int i;
    for (i = 0; i < n; ++i)
    {
        if (head == NULL)
            head = p;
        else
        {
            p->next = new ListNode();
            p = p->next;
        }
        p->val = arr[i];
        p->next = NULL;
    }
    return head;
}

/* Function to print linked list */
void printList(struct ListNode* head)
{
	struct ListNode* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->val);
		temp = temp->next;
	}
}
//int main(void)
//{
//    int arr[] = { 1,2,3,4,5 };
//    ListNode* head = createList(arr, 5);
//    printList(head);
//}
