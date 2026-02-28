/*Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true*/
#include <bits/stdc++.h>
using namespace std;

/*
   Structure of a Binary Search Tree node
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

/*
   BST Iterator class
   Works for both inorder and reverse inorder
*/
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

    /*
        Push nodes in stack based on direction
        inorder  -> left
        reverse  -> right
    */
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            if (!reverse)
                node = node->left;   // inorder
            else
                node = node->right;  // reverse inorder
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root, bool isreverse) {
        reverse = isreverse;
        pushAll(root);
    }

    /*
        Return next element
    */
    int next() {
        TreeNode* node = st.top();
        st.pop();

        // Push opposite subtree after popping
        if (!reverse) pushAll(node->right);
        else pushAll(node->left);

        return node->val;
    }

    /*
        Check if next element exists
    */
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    /*
        Function to check if there exist two nodes in BST
        whose sum is equal to k
    */
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        // Left iterator (smallest values)
        BSTIterator l(root, false);

        // Right iterator (largest values)
        BSTIterator r(root, true);

        int i = l.next(); // smallest
        int j = r.next(); // largest

        // Two pointer technique
        while (i < j) {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next(); // move left iterator forward
            else
                j = r.next(); // move right iterator backward
        }

        return false;
    }
};

/*
   Inorder traversal (for verification)
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

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertIntoBST(root, val);
    }

    cout << "Inorder traversal of BST: ";
    inorderPrint(root);
    cout << endl;

    int k;
    cout << "Enter target sum k: ";
    cin >> k;

    Solution sol;
    if (sol.findTarget(root, k))
        cout << "Two nodes exist with sum = " << k << endl;
    else
        cout << "No such pair exists with sum = " << k << endl;

    return 0;
}