/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true*/
#include <bits/stdc++.h>
using namespace std;

/*
   Structure of a Binary Tree node
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

/*
   Function to insert a value into BST (iterative)
   Just for building a test tree
*/
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    TreeNode* node = root;
    TreeNode* insertnode = new TreeNode(val);

    while (node != NULL) {
        if (val > node->val) {
            if (node->right == NULL) {
                node->right = insertnode;
                return root;
            } else {
                node = node->right;
            }
        } else {
            if (node->left == NULL) {
                node->left = insertnode;
                return root;
            } else {
                node = node->left;
            }
        }
    }
    return root;
}

class Solution {
    /*
       Helper function to validate BST
       Each node must satisfy: minVal < node->val < maxVal
    */
    bool helper(TreeNode* node, long long minVal, long long maxVal) {
        if (node == NULL) return true;

        if (node->val <= minVal || node->val >= maxVal) return false;

        // Check left subtree with updated max
        // Check right subtree with updated min
        return helper(node->left, minVal, node->val) &&
               helper(node->right, node->val, maxVal);
    }

public:
    /*
       Function to check if a binary tree is a BST
    */
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};

/*
   Inorder traversal (for checking tree)
*/
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    TreeNode* root = NULL;
    int n;

    cout << "Enter number of nodes to insert into BST: ";
    cin >> n;

    Solution sol;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertIntoBST(root, val);
    }

    cout << "Inorder traversal of tree: ";
    inorderPrint(root);
    cout << endl;

    if (sol.isValidBST(root))
        cout << "The tree is a valid BST.\n";
    else
        cout << "The tree is NOT a valid BST.\n";

    return 0;
}