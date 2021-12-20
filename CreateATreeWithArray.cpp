#include "CreateATreeWithArray.h"
#include<queue>   
using namespace std;

/* Helper function that allocates a
new node */
TreeNode* newNode(int val)
{
    if (val == INT_MIN)
        return NULL;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return (node);
}

TreeNode* build_tree(int nodes[], int n)
{
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    bool is_left = true;
    TreeNode* cur = NULL;
    q.push(root);

    for (int i = 1; i < n; i++) {
        TreeNode* node = NULL;
        if (nodes[i] != INT_MIN) {
            node = new TreeNode(nodes[i]);
            q.push(node);
        }

        if (is_left) {
            cur = q.front();
            q.pop();
            cur->left = node;
            is_left = false;
        }
        else {
            cur->right = node;
            is_left = true;
        }
    }

    return root;
}
void inOrder(TreeNode* root)
{
    if (!root)
        return;
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}
