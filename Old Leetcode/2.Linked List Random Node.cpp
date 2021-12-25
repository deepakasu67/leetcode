#include<iostream>
#include<ctime>
#include"LinkedList.h"
using namespace std;
class Solution {
public:
    ListNode* nodes[10000];
    int pos = 0;
    Solution(ListNode* head) {
        // initialising random generation
        srand(std::time(nullptr));
        // storing values in the array
        while (head) {
            nodes[pos++] = head;
            head = head->next;
        }
    }

    int getRandom() {
        // extracting a random element
        return nodes[rand() % pos]->val;
    }
};
