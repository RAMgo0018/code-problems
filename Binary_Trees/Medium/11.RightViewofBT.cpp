/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;                     // value of node
    TreeNode *left, *right;      // left and right child pointers
    TreeNode(int x) {
        val = x;                 // initialize value
        left = right = NULL;     // initialize children as NULL
    }
};

class Solution {
    void helper(TreeNode* node, int level, vector<int> &arr)   // recursive helper to build right view
    {
        if(node == NULL) return;                               // if node is NULL, return

        if(arr.size() == level)                                // if first time visiting this level
            arr.push_back(node->val);                          // store node value

        if(node->right) helper(node->right, level+1, arr);    // go to right child first
        if(node->left)  helper(node->left,  level+1, arr);    // then go to left child
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;                                       // vector to store right view
        helper(root, 0, arr);                                  // call helper starting from level 0
        return arr;                                            // return right view
    }
};

int main() {
    /*
            1
           / \
          2   3
           \   \
            5   4
    */

    TreeNode* root = new TreeNode(1);              // create root node
    root->left = new TreeNode(2);                  // create left child of root
    root->right = new TreeNode(3);                 // create right child of root
    root->left->right = new TreeNode(5);           // create right child of node 2
    root->right->right = new TreeNode(4);          // create right child of node 3

    Solution obj;                                  // create object of Solution class
    vector<int> result = obj.rightSideView(root);  // call rightSideView function

    cout << "Right Side View of Binary Tree: ";    // print message
    for(int x : result)                            // loop through result vector
        cout << x << " ";                          // print each element

    return 0;                                      // end of program
}
