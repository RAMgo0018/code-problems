/*Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

 

Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False*/
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
   It gives next smallest element each time (inorder traversal)
*/
class BSTIterator {
    stack<TreeNode*> st;

    /*
        Push all left nodes of a subtree into stack
    */
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor: initialize stack with leftmost path
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    /*
        Returns next smallest element
    */
    int next() {
        TreeNode* node = st.top();
        st.pop();

        // After visiting a node, process its right subtree
        pushAll(node->right);

        return node->val;
    }

    /*
        Checks if there is a next element
    */
    bool hasNext() {
        return !st.empty();
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

    // Create BST Iterator
    BSTIterator it(root);

    cout << "BST Iterator output: ";
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}