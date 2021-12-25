#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxPath(Node* root, int& ans)
    {
        if (root == nullptr)
            return 0;
        int firstMaxPath = 0;
        int secondMaxPath = 0;
        int diameterOfCurrentNode = 0;
        vector<Node*>& childrens = root->children;
        for(int i = 0; i < childrens.size(); i++)
        {
            int cuurMaxPath = maxPath(childrens[i], ans);

            if (firstMaxPath < cuurMaxPath) {
                secondMaxPath = firstMaxPath;
                firstMaxPath = cuurMaxPath;
            }
            else if (secondMaxPath < cuurMaxPath) {
                secondMaxPath = cuurMaxPath;
            }
        }
        ans = max(ans, firstMaxPath + secondMaxPath);
        return firstMaxPath + 1;

    }
    int diameter(Node* root)
    {
        int ans = 0;
        maxPath(root, ans);
        return ans;
    }
};

//int main(void)
//{
//    vector<Node*> firstLevel = { new Node(3),new Node(2),new Node(4) };
//    Node* root = new Node(1, firstLevel);
//    vector<Node*> secondLevel = { new Node(5), new Node(6) };
//    firstLevel[0]->children = secondLevel;
//    Solution obj;
//    obj.diameter(root);
//}