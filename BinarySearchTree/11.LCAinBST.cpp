/*Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.*/
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
public:
    /*
       Function to find LCA of nodes p and q in BST
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        int curr = root->val;

        // If p and q lie on different sides of root
        if ((p->val > curr && q->val < curr) ||
            (p->val < curr && q->val > curr)) {
            return root;
        }

        // Both on left side
        if (p->val < curr && q->val < curr) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Both on right side
        if (p->val > curr && q->val > curr) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // One of them is equal to root
        return root;
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

    vector<TreeNode*> nodes; // To store inserted nodes for LCA

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertIntoBST(root, val);
        nodes.push_back(root); // For simplicity, we will search by value later
    }

    cout << "Inorder traversal of BST: ";
    inorderPrint(root);
    cout << endl;

    int val1, val2;
    cout << "Enter two node values to find LCA: ";
    cin >> val1 >> val2;

    // Find the nodes in BST by value
    TreeNode* p = root;
    while (p && p->val != val1) {
        if (val1 < p->val) p = p->left;
        else p = p->right;
    }

    TreeNode* q = root;
    while (q && q->val != val2) {
        if (val2 < q->val) q = q->left;
        else q = q->right;
    }

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "Lowest Common Ancestor of " << val1 << " and " << val2 << " is: " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found.\n";

    return 0;
}