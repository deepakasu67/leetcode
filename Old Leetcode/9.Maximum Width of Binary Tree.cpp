#include<iostream>
#include<queue>
#include <unordered_map>

#include "CreateATreeWithArray.h"

using namespace std;
/*class Solution {
    int levelOfTree;
    vector<vector<int>> nodes;
    vector<int> levelIndex;
public:
    Solution()
    {
    }

    int leveloftree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return max(leveloftree(root->left), leveloftree(root->right)) + 1;
    }
    void createLeftSubtree(TreeNode*& root, int level)
    {
        if (level >= levelOfTree - 1)
            return;

        root->left = new TreeNode(INT_MIN);
        createLeftSubtree(root->left, level + 1);
        root->right = new TreeNode(INT_MIN);
        createLeftSubtree(root->right, level + 1);
    }
    void createDummyFullBinaryTree(TreeNode* root, int level)
    {

        if (root == nullptr)
        {
            return;
        }
        if (root->val == INT_MIN)
            return;
        if (level == levelOfTree - 1 && (!root->left && !root->right))
            return;
        if (root->left == nullptr)
        {
            TreeNode* dummyLeftSubtree = new TreeNode(INT_MIN);
            createLeftSubtree(dummyLeftSubtree, level + 1);
            root->left = dummyLeftSubtree;
        }
        if (root->right == nullptr)
        {
            TreeNode* dummyLeftSubtree = new TreeNode(INT_MIN);
            createLeftSubtree(dummyLeftSubtree, level + 1);
            root->right = dummyLeftSubtree;
        }
        createDummyFullBinaryTree(root->left, level + 1);
        createDummyFullBinaryTree(root->right, level + 1);
    }
    void widthofBinaryTreeUtil(TreeNode* root, const int level)
    {
        if (!root)
            return;
        nodes[level].push_back(root->val);
        widthofBinaryTreeUtil(root->left, level + 1);
        widthofBinaryTreeUtil(root->right, level + 1);
    }
    int widthOfBinaryTree(TreeNode* root)
    {
        return 0;
        if (root == nullptr)
            return 0;
        levelOfTree = leveloftree(root);
        nodes.resize(levelOfTree);

        createDummyFullBinaryTree(root, 0);

        widthofBinaryTreeUtil(root, 0);
        int maxWidth = 0;
        for (int i = 0; i < nodes.size(); i++)
        {
            int start = 0;
            int stop = 0;
            for (int j = 0; j < nodes[i].size(); j++)
            {
                if (nodes[i][j] != INT_MIN)
                {
                    start = j;
                    stop = start;
                    j++;
                    for (; j < nodes[i].size(); j++)
                    {
                        if (nodes[i][j] != INT_MIN)
                            stop = j;
                    }
                }
            }
            const int currentWidth = stop - start + 1;
            if (currentWidth > maxWidth)
            {
                maxWidth = currentWidth;
            }
        }
        return maxWidth;
    }
};*/
class Solution {
public:
    void widthOfBinaryTreeDFS(TreeNode* node, unordered_map<int, int>& hashmap, int& ans, int depth, int val)
    {
        if (node == nullptr)
        {
            return;
        }

        if (hashmap.find(depth) == hashmap.end())
        {
            hashmap[depth] = val;
        }

        int firstVal = hashmap[depth];
        ans = std::max(ans, val - firstVal + 1);

        widthOfBinaryTreeDFS(node->left, hashmap, ans, depth + 1, 2 * (long)val);
        widthOfBinaryTreeDFS(node->right, hashmap, ans, depth + 1, 2 * (long)val + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, int> hashmap;
        int ans = 0;

        widthOfBinaryTreeDFS(root, hashmap, ans, 0, 0);
        return ans;
    }
};
//int main(void)
//{
//    int nodes[] = {1,5,8,9,7,7,8,1,4,8,1,9,0,8,7,1,7,4,2,9,8,2,4,INT_MIN,INT_MIN,9,INT_MIN,INT_MIN,INT_MIN,6,0,9,4,1,0,1,8,9,0,1,8,9,1,0,9,6,2,5,INT_MIN,2,3,0,2,4,8,8,8,5,0,0,9,4,9,1,INT_MIN,0,7,2,2,3,INT_MIN,6,1,0,8,9,9,9,4,8,4,3,4,4,0,INT_MIN,INT_MIN,8,3,8,INT_MIN,INT_MIN,0,INT_MIN,0,4,9,1,2,INT_MIN,4,4,0,4,3,5,5,7,4,1,6,INT_MIN,1,0,INT_MIN,INT_MIN,INT_MIN,2,8,7,7,INT_MIN,INT_MIN,0,2,5,5,9,3,3,INT_MIN,7,6,6,7,9,8,1,7,7,7,2,6,INT_MIN,7,INT_MIN,4,6,4,6,INT_MIN,INT_MIN,9,1,INT_MIN,INT_MIN,INT_MIN,5,5,5,4,2,2,8,5,1,1,3,1,3,7,INT_MIN,2,INT_MIN,9,1,4,4,7,7,INT_MIN,1,5,6,2,7,3,INT_MIN,9,1,INT_MIN,2,4,4,8,INT_MIN,INT_MIN,7,INT_MIN,6,INT_MIN,7,4,3,5,8,4,8,5,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,4,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,3,5,5,INT_MIN,INT_MIN,INT_MIN,1,2,0,INT_MIN,INT_MIN,9,3,INT_MIN,8,3,7,1,8,9,0,1,8,2,INT_MIN,4,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,4,8,5,5,3,1,INT_MIN,INT_MIN,6,INT_MIN,1,INT_MIN,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,3,INT_MIN,INT_MIN,INT_MIN,8,6,4,INT_MIN,6,9,0,7,8,INT_MIN,INT_MIN,0,6,7,INT_MIN,INT_MIN,0,0,7,2,3,2,INT_MIN,0,2,3,INT_MIN,0,1,7,9,0,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,8,2,6,3,2,0,4,INT_MIN,INT_MIN,0,9,1,1,1,INT_MIN,1,3,INT_MIN,7,9,1,3,3,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,8,1,3,8,3,0,6,INT_MIN,INT_MIN,8,5,6,5,2,1,INT_MIN,5,INT_MIN,7,0,0,INT_MIN,9,3,9,INT_MIN,3,0,0,9,1,7,0,2,INT_MIN,6,8,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,2,5,INT_MIN,INT_MIN,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,1,INT_MIN,3,6,6,2,5,5,9,INT_MIN,INT_MIN,7,8,INT_MIN,INT_MIN,2,7,3,7,2,5,INT_MIN,1,3,4,INT_MIN,INT_MIN,8,3,6,9,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,7,5,2,INT_MIN,5,INT_MIN,6,4,5,INT_MIN,1,2,0,6,INT_MIN,1,6,INT_MIN,INT_MIN,5,INT_MIN,7,8,4,7,8,6,4,INT_MIN,5,6,7,9,1,0,4,INT_MIN,INT_MIN,INT_MIN,6,4,8,4,5,INT_MIN,0,4,4,0,1,7,1,INT_MIN,1,INT_MIN,3,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,5,0,7,5,INT_MIN,INT_MIN,5,8,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,8,INT_MIN,2,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,INT_MIN,9,INT_MIN,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,1,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,5,5,5,5,6,4,INT_MIN,INT_MIN,1,6,4,0,INT_MIN,0,6,3,0,INT_MIN,5,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,3,6,INT_MIN,3,0,5,0,1,0,3,4,9,9,2,7,3,8,6,9,INT_MIN,5,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,8,0,7,INT_MIN,INT_MIN,8,8,6,6,0,2,7,4,2,3,8,6,4,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,2,0,INT_MIN,1,3,5,4,2,2,5,8,8,INT_MIN,3,0,INT_MIN,1,6,0,INT_MIN,INT_MIN,9,INT_MIN,2,INT_MIN,6,8,2,INT_MIN,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,9,6,6,4,2,0,INT_MIN,INT_MIN,1,INT_MIN,0,INT_MIN,INT_MIN,INT_MIN,6,6,INT_MIN,INT_MIN,INT_MIN,4,7,9,INT_MIN,0,1,INT_MIN,INT_MIN,9,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,6,INT_MIN,3,INT_MIN,INT_MIN,5,1,2,5,INT_MIN,0,7,8,INT_MIN,7,INT_MIN,INT_MIN,4,INT_MIN,4,4,INT_MIN,2,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,6,4,INT_MIN,6,INT_MIN,6,9,INT_MIN,INT_MIN,INT_MIN,9,6,INT_MIN,9,INT_MIN,3,INT_MIN,2,INT_MIN,7,7,INT_MIN,INT_MIN,0,INT_MIN,6,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,6,9,7,INT_MIN,7,INT_MIN,9,3,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,3,9,INT_MIN,0,3,1,9,6,7,9,4,8,INT_MIN,INT_MIN,6,INT_MIN,1,3,7,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,2,INT_MIN,8,1,1,INT_MIN,INT_MIN,6,INT_MIN,7,3,5,INT_MIN,6,3,4,INT_MIN,INT_MIN,5,7,1,INT_MIN,INT_MIN,6,4,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,7,0,7,0,INT_MIN,5,8,5,5,4,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,7,INT_MIN,INT_MIN,7,INT_MIN,9,9,6,4,INT_MIN,INT_MIN,3,2,1,INT_MIN,0,INT_MIN,0,6,INT_MIN,INT_MIN,INT_MIN,1,5,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,4,8,INT_MIN,INT_MIN,9,6,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,9,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,INT_MIN,INT_MIN,INT_MIN,4,1,6,7,0,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,0,6,INT_MIN,5,INT_MIN,9,9,INT_MIN,INT_MIN,4,3,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,2,1,8,5,INT_MIN,0,INT_MIN,0,3,2,4,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,0,INT_MIN,0,INT_MIN,INT_MIN,INT_MIN,0,3,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,INT_MIN,INT_MIN,0,5,0,0,INT_MIN,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,9,3,5,9,0,5,9,INT_MIN,INT_MIN,9,4,INT_MIN,0,2,0,INT_MIN,INT_MIN,7,INT_MIN,7,INT_MIN,5,7,8,7,INT_MIN,INT_MIN,INT_MIN,3,0,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,5,INT_MIN,INT_MIN,2,3,INT_MIN,2,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,9,INT_MIN,INT_MIN,9,7,1,INT_MIN,INT_MIN,1,6,1,8,INT_MIN,INT_MIN,5,INT_MIN,INT_MIN,3,7,9,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,3,7,3,2,3,3,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,4,3,4,8,7,INT_MIN,0,3,0,INT_MIN,1,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,INT_MIN,6,0,INT_MIN,3,1,INT_MIN,6,INT_MIN,INT_MIN,4,0,1,INT_MIN,6,1,INT_MIN,INT_MIN,9,6,4,9,0,8,9,3,3,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,5,8,3,5,4,INT_MIN,6,INT_MIN,0,INT_MIN,INT_MIN,6,INT_MIN,4,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,3,INT_MIN,INT_MIN,1,INT_MIN,2,4,INT_MIN,INT_MIN,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,6,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,3,INT_MIN,1,INT_MIN,7,1,INT_MIN,INT_MIN,7,1,3,4,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,6,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,7,3,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,0,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,9,INT_MIN,INT_MIN,6,6,5,2,INT_MIN,8,3,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,6,7,0,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,1,5,INT_MIN,0,5,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,1,2,INT_MIN,2,9,1,INT_MIN,2,4,1,INT_MIN,INT_MIN,INT_MIN,1,8,4,4,5,2,INT_MIN,INT_MIN,6,4,7,5,2,9,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,5,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,INT_MIN,9,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,1,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,9,3,INT_MIN,INT_MIN,1,9,INT_MIN,5,2,1,0,INT_MIN,INT_MIN,1,9,8,4,7,INT_MIN,INT_MIN,5,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,2,8,INT_MIN,6,0,INT_MIN,INT_MIN,INT_MIN,INT_MIN,0,INT_MIN,INT_MIN,INT_MIN,6,INT_MIN,2,3,0,9,INT_MIN,INT_MIN,1,4,6,INT_MIN,8,INT_MIN,INT_MIN,5,INT_MIN,3,0,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,5,8,6,9,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,9,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,INT_MIN,6,INT_MIN,2,5,INT_MIN,INT_MIN,1,2,INT_MIN,4,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,3,5,INT_MIN,3,3,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,2,3,INT_MIN,4,5,3,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,7,6,INT_MIN,INT_MIN,1,3,INT_MIN,4,9,8,INT_MIN,INT_MIN,0,INT_MIN,3,4,INT_MIN,8,INT_MIN,1,INT_MIN,INT_MIN,2,2,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,7,5,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,0,INT_MIN,3,INT_MIN,1,INT_MIN,9,4,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,5,7,INT_MIN,INT_MIN,1,INT_MIN,4,6,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,5,9,0,6,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,INT_MIN,7,INT_MIN,2,9,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,1,6,INT_MIN,6,INT_MIN,INT_MIN,0,8,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,0,INT_MIN,6,0,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,0,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,0,5,4,2,6,4,5,3,4,INT_MIN,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,3,6,2,0,INT_MIN,6,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,0,6,INT_MIN,INT_MIN,INT_MIN,3,9,4,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,0,INT_MIN,INT_MIN,6,7,0,INT_MIN,9,2,INT_MIN,3,3,INT_MIN,INT_MIN,8,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,8,5,3,INT_MIN,2,4,INT_MIN,9,6,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,6,INT_MIN,6,INT_MIN,5,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,9,0,9,7,1,1,INT_MIN,1,INT_MIN,1,6,INT_MIN,5,INT_MIN,6,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,6,1,INT_MIN,0,2,INT_MIN,INT_MIN,0,INT_MIN,INT_MIN,0,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,5,3,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,0,8,7,INT_MIN,INT_MIN,8,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,2,INT_MIN,2,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1,5,0,INT_MIN,INT_MIN,2,INT_MIN,7,INT_MIN,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,0,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,5,INT_MIN,3,4,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,7,INT_MIN,INT_MIN,INT_MIN,4,0,3,INT_MIN,INT_MIN,6,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,0,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,8,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,2,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,0,5};
//    TreeNode* root = build_tree(nodes, 2098);
//    Solution obj;
//    cout << obj.widthOfBinaryTree(root);
//}