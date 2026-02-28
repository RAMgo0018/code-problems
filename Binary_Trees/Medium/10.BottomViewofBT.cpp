/*You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

Examples :

Input: root = [1, 2, 3, 4, 5, N, 6]
    
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tre*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;                  // value of node
    Node *left, *right;        // left and right child pointers
    Node(int x) {
        data = x;              // initialize data
        left = right = NULL;   // initialize children as NULL
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;                       // vector to store answer
        if(root == NULL) return ans;           // if tree is empty, return empty vector

        map<int,int> mpp;                      // map to store latest node for each horizontal distance
        queue<pair<Node*,int>> q;              // queue for BFS (node, horizontal distance)

        q.push({root,0});                      // push root with horizontal distance 0

        while(!q.empty())
        {
            auto it = q.front();               // get front element from queue
            q.pop();                           // remove front element

            Node* node = it.first;             // current node
            int line = it.second;              // horizontal distance of current node
            mpp[line] = node->data;            // update map so bottom-most node stays

            if(node->left)                     // if left child exists
                q.push({node->left, line-1});  // push left child with distance -1

            if(node->right)                    // if right child exists
                q.push({node->right, line+1}); // push right child with distance +1
        }

        for(auto it : mpp)                     // traverse map in sorted order of keys
        {
            ans.push_back(it.second);          // store values in answer vector
        }

        return ans;                            // return bottom view
    }
};

int main() {
    /*
            20
           /  \
          8   22
         / \    \
        5  3     25
          / \
         10 14
    */

    Node* root = new Node(20);                         // create root node
    root->left = new Node(8);                          // create left child of root
    root->right = new Node(22);                        // create right child of root
    root->left->left = new Node(5);                    // create left child of node 8
    root->left->right = new Node(3);                   // create right child of node 8
    root->right->right = new Node(25);                 // create right child of node 22
    root->left->right->left = new Node(10);            // create left child of node 3
    root->left->right->right = new Node(14);           // create right child of node 3

    Solution obj;                                      // create object of Solution class
    vector<int> result = obj.bottomView(root);         // call bottomView function

    cout << "Bottom View of Binary Tree: ";            // print message
    for(int x : result)                                // loop through result vector
        cout << x << " ";                              // print each element

    return 0;                                          // end of program
}
