#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


// -------- Your code (UNCHANGED) --------
class Solution {
    void helper(Node* root, int &mn)
    {
        if(root == NULL) return;   // If tree is empty, return

        mn = root->data;           // Update minimum with current node's data
        helper(root->left, mn);    // Move to left child (smaller values in BST)
    }

  public:
    int minValue(Node* root) {
        int mn = INT_MAX;          // Initialize min value as very large
        helper(root, mn);          // Call helper to find leftmost node
        return mn;                 // Return minimum value
    }
};
// --------------------------------------

// -------- MAIN FUNCTION --------
int main() {
    /*
        Tree from input:
        root = [5, 4, 6, 3, N, N, 7, 1]

                5
               / \
              4   6
             /     \
            3       7
           /
          1
    */

    // Creating nodes as per given tree
    Node* root = new Node(5);           // root node

    root->left = new Node(4);           // left child of 5
    root->right = new Node(6);          // right child of 5

    root->left->left = new Node(3);     // left child of 4
    root->right->right = new Node(7);   // right child of 6

    root->left->left->left = new Node(1); // left child of 3

    Solution obj;                       // Create Solution object

    int ans = obj.minValue(root);       // Find minimum value in BST

    cout << "Minimum value in BST: " << ans << endl;

    return 0;
}