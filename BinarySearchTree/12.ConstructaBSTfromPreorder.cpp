/*Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]*/
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

class Solution {

    /*
        Helper function to build BST from preorder traversal
        i     -> current index in preorder array
        bound -> maximum allowed value for current subtree
    */
    TreeNode* helper(vector<int>& preorder, int &i, int bound) {
        // If all elements are used OR current value exceeds bound
        if (i >= preorder.size() || preorder[i] > bound)
            return NULL;

        // Create root node with current preorder value
        TreeNode* root = new TreeNode(preorder[i]);
        i++;  // Move to next element in preorder

        // All values smaller than root->val go to left subtree
        root->left = helper(preorder, i, root->val);

        // All values between root->val and bound go to right subtree
        root->right = helper(preorder, i, bound);

        return root;
    }

public:
    /*
        Function to construct BST from preorder traversal
    */
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};

/*
   Inorder traversal (to verify BST)
   Inorder of BST should be sorted
*/
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes in preorder: ";
    cin >> n;

    vector<int> preorder(n);
    cout << "Enter preorder traversal:\n";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    Solution sol;

    // Build BST from preorder traversal
    TreeNode* root = sol.bstFromPreorder(preorder);

    // Print inorder traversal to verify BST
    cout << "Inorder traversal of constructed BST: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}