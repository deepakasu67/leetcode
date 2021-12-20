#pragma once
#include <iostream> 
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


/* Function to push a node */
ListNode* createList(int* arr, int n);

/* Function to print linked list */
void printList(struct ListNode* head);

