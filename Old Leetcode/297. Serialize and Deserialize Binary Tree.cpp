#include<iostream>
#include"CreateATreeWithArray.h"
#include<string>
#include<cstdio>
#include<queue>
#include<sstream>
using namespace std;

//class Codec {
//public:
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        if (root == nullptr) return "#";
//        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        return mydeserialize(data);
//    }
//    TreeNode* mydeserialize(string& data) {
//        if (data[0] == '#') {
//            if (data.size() > 1) data = data.substr(2);
//            return nullptr;
//        }
//        else {
//            TreeNode* node = new TreeNode(helper(data));
//            node->left = mydeserialize(data);
//            node->right = mydeserialize(data);
//            return node;
//        }
//    }
//private:
//    int helper(string& data) {
//        int pos = data.find(',');
//        int val = stoi(data.substr(0, pos));
//        data = data.substr(pos + 1);
//        return val;
//    }
//};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    int i = 0;
    string serialize(TreeNode* root) {
        if (root == nullptr)
        {
            return "#";
        }
        string rootStr = to_string(root->val);
        string leftSubtree = serialize(root->left);
        string rightSubtree= serialize(root->right);
        return rootStr + "|" + leftSubtree + "|" + rightSubtree;
    }

    void extractAllNodes(string& data, vector<string>& nodes)
    {
        stringstream s(data);
        string nodeData;
        while (getline(s, nodeData, '|'))
        {
            if(nodeData != "")
                nodes.push_back((nodeData));
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(vector<string>& nodes)
    {
        if (nodes[i] == "#")
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;
        root->left = deserialize(nodes);
        i++;
        root->right = deserialize(nodes);
        return root;

    }
    TreeNode* deserialize(string data) 
    {
        vector<string> nodes;
        extractAllNodes(data, nodes);
        return deserialize(nodes);
    
    }
};


//int main(void)
//{
//    int arr[] = { 1,2,3,INT_MIN,INT_MIN,4,5 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    int i;
//    cout << sscanf_s("-123", "%d", &i)<<endl;
//    cout << i << endl;
//    Codec obj;
//    obj.deserialize(obj.serialize(root));
//
//
//}