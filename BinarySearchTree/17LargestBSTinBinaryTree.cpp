/*Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.*/
#include <bits/stdc++.h>
using namespace std;

/*
   Structure of a Binary Tree node
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
   Class to store information about subtree
   minval -> minimum value in subtree
   maxval -> maximum value in subtree
   size   -> size of largest BST in this subtree
*/
class NodeValue {
public:
    int minval;
    int maxval;
    int size;

    NodeValue(int minvalue, int maxvalue, int sizee) {
        minval = minvalue;
        maxval = maxvalue;
        size = sizee;
    }
};

class Solution {
    /*
        Helper function returns NodeValue for each subtree
    */
    NodeValue helper(TreeNode* root) {
        // Base case: empty tree is BST of size 0
        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        // Get info from left and right subtrees
        NodeValue left = helper(root->left);
        NodeValue right = helper(root->right);

        // Check if current subtree is BST
        if (root->val > left.maxval && root->val < right.minval) {
            // Valid BST → update range and size
            return NodeValue(
                min(root->val, left.minval),   // new minimum
                max(root->val, right.maxval),  // new maximum
                left.size + right.size + 1     // total size
            );
        }

        // Not a BST → return invalid range but keep max size found so far
        return NodeValue(INT_MIN, INT_MAX, max(left.size, right.size));
    }

public:
    /*
        Function to return size of largest BST in the tree
    */
    int maxSumBST(TreeNode* root) {
        return helper(root).size;
    }
};

/*
   Inorder traversal (for viewing tree)
*/
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

/*
   Insert node into BST (for building test tree easily)
*/
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
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

    cout << "Inorder traversal of tree: ";
    inorderPrint(root);
    cout << endl;

    Solution sol;
    int ans = sol.maxSumBST(root);

    cout << "Size of largest BST in the tree: " << ans << endl;

    return 0;
}