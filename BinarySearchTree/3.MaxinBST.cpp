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


// -------- Your code (for MAX value) --------
class Solution {
    void helper(Node* root, int &mx)
    {
        if(root == NULL) return;   // If tree is empty, return

        mx = root->data;           // Update maximum with current node's data
        helper(root->right, mx);   // Move to right child (larger values in BST)
    }

  public:
    int maxValue(Node* root) {
        int mx = INT_MIN;          // Initialize max value as very small
        helper(root, mx);          // Call helper to go to rightmost node
        return mx;                 // Return maximum value
    }
};
// ------------------------------------------

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

        Maximum value = 7
    */

    Node* root = new Node(5);           // root node

    root->left = new Node(4);           // left child of 5
    root->right = new Node(6);          // right child of 5

    root->left->left = new Node(3);     // left child of 4
    root->right->right = new Node(7);   // right child of 6

    root->left->left->left = new Node(1); // left child of 3

    Solution obj;                       // Create Solution object

    int ans = obj.maxValue(root);       // Find maximum value in BST

    cout << "Maximum value in BST: " << ans << endl;

    return 0;
}