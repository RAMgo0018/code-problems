/*You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]*/
#include <bits/stdc++.h>
using namespace std;

/*
   Structure of a Binary Search Tree node
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to create a new node
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    /*
        Function to insert a value into BST (Iterative method)
    */
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If tree is empty, create a new node and return it
        if(root == NULL)
            return new TreeNode(val);

        // Create the new node to be inserted
        TreeNode* insertnode = new TreeNode(val);

        // Start traversal from root
        TreeNode* node = root;

        // Traverse until we find correct position
        while(node != NULL)
        {
            // If value is greater, go to right subtree
            if(val > node->val)
            {
                // If right child is empty, insert here
                if(node->right == NULL)
                {
                    node->right = insertnode;
                    return root;
                }
                else
                {
                    node = node->right; // move right
                }
            }
            else
            {
                // If value is smaller or equal, go to left subtree
                if(node->left == NULL)
                {
                    node->left = insertnode;
                    return root;
                }
                else
                {
                    node = node->left; // move left
                }
            }
        }

        return root;
    }
};

/*
   Inorder traversal (prints BST in sorted order)
*/
void inorder(TreeNode* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;
    int n;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    Solution obj;

    // Insert nodes into BST
    cout << "Enter node values:\n";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = obj.insertIntoBST(root, val);
    }

    // Print inorder traversal (should be sorted)
    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}