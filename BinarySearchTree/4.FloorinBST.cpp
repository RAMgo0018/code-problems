/*You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Examples:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output: 87
Explanation: 87 is present in tree so floor will be 87.*/
#include <bits/stdc++.h>
using namespace std;

/* 
   Structure of a Binary Search Tree node
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/*
   Function to insert a value in BST
*/
Node* insert(Node* root, int key) {
    // If tree is empty, create a new node
    if (root == NULL) 
        return new Node(key);

    // If key is smaller, go to left subtree
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

class Solution {

    /*
        Helper function (recursive) to find floor value
        flo stores the best possible floor found so far
    */
    int helper(Node* root, int x, int &flo)
    {
        // If we reach NULL, return the stored floor
        if(root == NULL) 
            return flo;

        // If exact value is found, it is the floor
        if(root->data == x) 
            return root->data;

        // If current node value is smaller than x,
        // it can be a possible floor
        if(root->data < x)
        {
            flo = root->data;          // update possible floor
            return helper(root->right, x, flo);  // go right
        }
        else
        {
            // If current node value is greater than x,
            // go to left subtree
            return helper(root->left, x, flo);
        }
    }

  public:
    /*
        Function to find floor of value x in BST
    */
    int floor(Node* root, int x) {
        int flo = -1;   // Default value if floor does not exist
        return helper(root, x, flo);
    }
};

int main() {
    Node* root = NULL;
    int n;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Input node values and insert into BST
    cout << "Enter node values:\n";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int x;
    // Input value for which floor is required
    cout << "Enter value to find floor: ";
    cin >> x;

    Solution obj;

    // Find floor value
    int ans = obj.floor(root, x);

    // Print result
    cout << "Floor of " << x << " is: " << ans << endl;

    return 0;
}