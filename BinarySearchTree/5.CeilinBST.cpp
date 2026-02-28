/*You are given a root binary search tree and an integer x . Your task is to find the Ceil of x in the tree.
Note: Ceil(x) is a number that is either equal to x or is immediately greater than x.
If Ceil could not be found, return -1.

Examples:

Input: root = [5, 1, 7, N, 2, N, N, N, 3], x = 3

Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.*/
#include <bits/stdc++.h>
using namespace std;

/*
   Structure of a Binary Search Tree node
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/*
   Function to insert a value into BST
*/
Node* insert(Node* root, int key) {
    // If tree is empty, create a new node
    if (root == NULL)
        return new Node(key);

    // Insert according to BST property
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

class Solution {

    /*
        Helper function to find ceil value
        cei stores the best possible ceil found so far
    */
    int helper(Node* root, int x, int &cei)
    {
        // If we reach NULL, return stored ceil
        if(root == NULL)
            return cei;

        // If exact value is found, it is the ceil
        if(root->data == x)
            return root->data;

        // If current node value is greater than x,
        // it can be a possible ceil
        if(root->data > x)
        {
            cei = root->data;                 // update possible ceil
            return helper(root->left, x, cei); // go left
        }
        else
        {
            // If current node value is smaller than x,
            // go to right subtree
            return helper(root->right, x, cei);
        }
    }

  public:
    /*
        Function to find ceil of x in BST
    */
    int findCeil(Node* root, int x) {
        int cei = -1;     // Default if ceil does not exist
        return helper(root, x, cei);
    }
};

int main() {
    Node* root = NULL;
    int n;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Input node values
    cout << "Enter node values:\n";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int x;
    // Input value whose ceil is needed
    cout << "Enter value to find ceil: ";
    cin >> x;

    Solution obj;

    // Find ceil
    int ans = obj.findCeil(root, x);

    // Print result
    cout << "Ceil of " << x << " is: " << ans << endl;

    return 0;
}