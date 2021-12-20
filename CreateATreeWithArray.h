#pragma once
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Helper function that allocates a
new node */
TreeNode* newNode(int val);

// Function to insert nodes in level order 
TreeNode* build_tree(int arr[], int n);
void inOrder(TreeNode* root);