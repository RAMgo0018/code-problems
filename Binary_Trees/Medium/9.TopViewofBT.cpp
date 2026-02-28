/*You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;                  // value of node
    Node *left, *right;        // left and right child pointers
    Node(int val) {
        data = val;            // initialize data
        left = right = NULL;   // initialize children as NULL
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;                       // vector to store answer
        if(root == NULL) return ans;           // if tree is empty, return empty vector

        map<int,int> mpp;                      // map to store first node for each horizontal distance
        queue<pair<Node*,int>> q;              // queue for BFS (node, horizontal distance)

        q.push({root,0});                      // push root with horizontal distance 0

        while(!q.empty())
        {
            auto it = q.front();               // get front element from queue
            q.pop();                           // remove front element

            Node* node = it.first;             // current node
            int line = it.second;              // horizontal distance of current node

            if(mpp.find(line) == mpp.end())    // if this horizontal distance is not yet in map
                mpp[line] = node->data;        // store node value for this distance

            if(node->left)                     // if left child exists
                q.push({node->left, line-1});  // push left child with distance -1

            if(node->right)                    // if right child exists
                q.push({node->right, line+1}); // push right child with distance +1
        }

        for(auto it : mpp)                     // traverse map in sorted order of keys
        {
            ans.push_back(it.second);          // store values in answer vector
        }

        return ans;                            // return top view
    }
};

int main() {
    /*
            1
           / \
          2   3
           \
            4
             \
              5
               \
                6
    */

    Node* root = new Node(1);                          // create root node
    root->left = new Node(2);                          // create left child of root
    root->right = new Node(3);                         // create right child of root
    root->left->right = new Node(4);                   // create right child of node 2
    root->left->right->right = new Node(5);            // create right child of node 4
    root->left->right->right->right = new Node(6);     // create right child of node 5

    Solution obj;                                      // create object of Solution class
    vector<int> result = obj.topView(root);            // call topView function

    cout << "Top View of Binary Tree: ";               // print message
    for(int x : result)                                // loop through result vector
        cout << x << " ";                              // print each element

    return 0;                                          // end of program
}
