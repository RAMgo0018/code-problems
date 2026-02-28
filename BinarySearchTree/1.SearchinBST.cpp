/*You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]*/
#include <bits/stdc++.h>
using namespace std;

/*
 Definition of Binary Tree Node
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(NULL), right(NULL) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 Function to insert a value into BST
 (used to build tree from user input)
*/
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

/*
 Solution class (same as LeetCode)
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Keep moving until root becomes NULL or value is found
        while(root != NULL && root->val != val) {
            // If target value is greater, move right
            if(root->val < val)
                root = root->right;
            // Otherwise move left
            else
                root = root->left;
        }
        // Return node if found, else NULL
        return root;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    TreeNode* root = NULL;

    cout << "Enter values to insert in BST:\n";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertIntoBST(root, x);
    }

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    Solution obj;
    TreeNode* result = obj.searchBST(root, key);

    if(result != NULL)
        cout << "Value found in BST: " << result->val << endl;
    else
        cout << "Value not found in BST" << endl;

    return 0;
}