/*You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.*/
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
   Inorder traversal (prints tree in sorted order if BST is valid)
*/
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

/*
   Solution class to recover BST
*/
class Solution {
    TreeNode* first = NULL;   // first wrong node
    TreeNode* middle = NULL;  // middle node (adjacent case)
    TreeNode* last = NULL;    // last wrong node (non-adjacent case)
    TreeNode* prev = NULL;    // previous node in inorder traversal

    /*
        Inorder traversal to detect swapped nodes
    */
    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        // Detect violation of BST property
        if (prev != NULL && prev->val > root->val) {
            if (first == NULL) {
                // First violation
                first = prev;
                middle = root;
            } else {
                // Second violation
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    /*
        Function to fix the BST by swapping back values
    */
    void recoverTree(TreeNode* root) {
        inorder(root);

        // Case 1: non-adjacent nodes swapped
        if (first && last)
            swap(first->val, last->val);

        // Case 2: adjacent nodes swapped
        else if (first && middle)
            swap(first->val, middle->val);
    }
};

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

    cout << "Inorder traversal before recovery: ";
    inorderPrint(root);
    cout << endl;

    Solution sol;

    // Recover the BST
    sol.recoverTree(root);

    cout << "Inorder traversal after recovery: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}