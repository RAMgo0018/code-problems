/*You are given the root of a BST and an integer key. You need to find the inorder predecessor and successor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note: In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Examples :

Input: root = [50, 30, 70, 20, 40, 60, 80], key = 65

Output: [60, 70]
Explanation: In the given BST the inorder predecessor of 65 is 60 and inorder successor of 65 is 70.*/
#include <bits/stdc++.h>
using namespace std;

/*
   Structure of a Binary Search Tree node
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/*
   Function to insert a value into BST (iterative)
*/
Node* insertIntoBST(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    Node* node = root;
    Node* insertnode = new Node(val);

    while (node != NULL) {
        if (val > node->data) {
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
public:
    /*
        Function to find predecessor and successor of a given key in BST
        Predecessor = largest value smaller than key
        Successor   = smallest value greater than key
    */
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* node = root;

        // -------- Find Successor --------
        while (node != NULL) {
            if (node->data > key) {
                suc = node;           // possible successor
                node = node->left;   // move left for smaller value
            } else {
                node = node->right;  // move right
            }
        }

        node = root; // reset pointer for predecessor

        // -------- Find Predecessor --------
        while (node != NULL) {
            if (node->data < key) {
                pre = node;           // possible predecessor
                node = node->right;  // move right for larger value
            } else {
                node = node->left;   // move left
            }
        }

        return {pre, suc};
    }
};

/*
   Inorder traversal (to check BST)
*/
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = NULL;
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

    int key;
    cout << "Enter key to find predecessor and successor: ";
    cin >> key;

    Solution sol;
    vector<Node*> result = sol.findPreSuc(root, key);

    if (result[0] != NULL)
        cout << "Predecessor: " << result[0]->data << endl;
    else
        cout << "Predecessor: NULL" << endl;

    if (result[1] != NULL)
        cout << "Successor: " << result[1]->data << endl;
    else
        cout << "Successor: NULL" << endl;

    return 0;
}