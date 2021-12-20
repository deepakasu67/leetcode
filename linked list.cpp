#include<iostream>
#include<vector>
using namespace std;

struct node 
{
	int val;
	node* next;
	node(int val) 
	{
		this->val = val;
		next = nullptr;
	}
};

void displayLinkedList(node* head)
{
	node* tempIterator = head;
	while (tempIterator)
	{
		cout << tempIterator->val;
		tempIterator = tempIterator->next;
	}
	cout << endl;
}

node* createLinkedList(vector<int>& nums)
{
	node* head = nullptr;
	node* tail = nullptr;
	for (int i = 0; i < nums.size(); i++)
	{
		node* newNode = new node(nums[i]);
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		tail->next = newNode;
		tail = newNode;
	}
	return head;
}

void insertAtKElement(node*& head, int val,int k)
{
	node* newNode = new node(val);
	if (k == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	
	node* tempIt = head, *tail = nullptr;
	while (tempIt != nullptr && k > 0)
	{
		tail = tempIt;
		tempIt = tempIt->next;
		k--;
	}
	
	if (k > 0)
		return;
	newNode->next = tail->next;
	tail->next = newNode;
}
//
//int main(void)
//{
//	vector<int> nums = { 1,2,3,4,5,6,7 };
//	node *head = createLinkedList(nums);
//	displayLinkedList(head);
//	insertAtKElement(head, 0, 1);
//	displayLinkedList(head);
//	insertAtKElement(head, 5, 5);
//	displayLinkedList(head);
//	insertAtKElement(head, 8, 9);
//	displayLinkedList(head);
//} 