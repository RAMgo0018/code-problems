/*Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1*/
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

class Solution {
    /*
       Recursive inorder traversal.
       k is decremented each time we visit a node.
       When k==0, we found the kth smallest element.
    */
    int inorder(TreeNode* root, int &k) {
        if (root == NULL) return -1;

        // Search in left subtree
        int left = inorder(root->left, k);
        if (left != -1) return left;

        // Visit current node
        k--;
        if (k == 0) return root->val;

        // Search in right subtree
        return inorder(root->right, k);
    }

public:
    /*
       Function to return kth smallest element in BST
    */
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};

/*
   Inorder traversal (for checking BST)
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

    Solution sol;

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
    cout << "Enter k to find kth smallest element: ";
    cin >> k;

    int ans = sol.kthSmallest(root, k);
    cout << k << "th smallest element is: " << ans << endl;

    return 0;
}