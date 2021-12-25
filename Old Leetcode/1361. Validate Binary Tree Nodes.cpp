#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int rootIdx, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited)
    {
        if (rootIdx == -1)
        {
            return true;
        }
        if (visited[rootIdx] == true)
        {
            return false;
        }
        visited[rootIdx] = true;

        return validateBinaryTreeNodes(leftChild[rootIdx], leftChild, rightChild, visited) &&
               validateBinaryTreeNodes(rightChild[rootIdx], leftChild, rightChild, visited);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<bool> visited(leftChild.size(), false);
        vector<int> parent(leftChild.size(), -1);
        int root = 0;
        for (int i = 0; i < n; i++) // first find the parents
        {
            if (leftChild[i] >= 0)
            {
                parent[leftChild[i]] = i;
            }
            if (rightChild[i] >= 0)
            {
                parent[rightChild[i]] = i;
            }
        }
        for (int i = 0; i < n; i++) // there would be only one root node.
        {
            if (parent[i] == -1)
                root = i;
        }
        bool isBinaryTree = validateBinaryTreeNodes(root, leftChild, rightChild, visited); // find which all nodes are visited with the above root node
        
        int countOfVisitedNode = 0;

        for (bool isVisited : visited)
        {
            if (isVisited == true)
            {
                countOfVisitedNode++;
            }
        }

        return (countOfVisitedNode == n) && isBinaryTree; // check if the binary tree that we have found have visited all the nodes
    }
};
//
//int main(void)
//{
//    vector<int> leftChild = { 3,-1,1,-1 };
//    vector<int> rightChild = { -1,-1,0,-1 };
//    Solution obj;
//    cout<<obj.validateBinaryTreeNodes(4, leftChild, rightChild);
//}