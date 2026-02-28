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
       Reverse inorder traversal: right → root → left
       k is decremented each time we visit a node.
       When k==0, we found the kth largest element.
    */
    int reverseInorder(TreeNode* root, int &k) {
        if (root == NULL) return -1;

        // Search in right subtree first (largest values)
        int right = reverseInorder(root->right, k);
        if (right != -1) return right;

        // Visit current node
        k--;
        if (k == 0) return root->val;

        // Search in left subtree
        return reverseInorder(root->left, k);
    }

public:
    /*
       Function to return kth largest element in BST
    */
    int kthLargest(TreeNode* root, int k) {
        return reverseInorder(root, k);
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
    cout << "Enter k to find kth largest element: ";
    cin >> k;

    int ans = sol.kthLargest(root, k);
    cout << k << "th largest element is: " << ans << endl;

    return 0;
}