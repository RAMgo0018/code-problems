/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;                     // value of node
    TreeNode *left, *right;      // left and right child pointers
    TreeNode(int x) {
        val = x;                 // initialize value
        left = right = NULL;     // initialize children as NULL
    }
};

class Solution {
    bool helper(TreeNode* leftNode, TreeNode* rightNode)   // helper to compare two subtrees
    {
        if(leftNode == NULL && rightNode == NULL) return true;    // both nodes NULL means symmetric
        if(leftNode == NULL || rightNode == NULL) return false;  // one NULL and other not means not symmetric

        if(leftNode->val != rightNode->val) return false;         // values must be equal

        return helper(leftNode->left, rightNode->right) &&        // check outer children
               helper(leftNode->right, rightNode->left);         // check inner children
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;                             // empty tree is symmetric
        return helper(root->left, root->right);                  // compare left and right subtrees
    }
};

int main() {
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */

    TreeNode* root = new TreeNode(1);              // create root node
    root->left = new TreeNode(2);                  // create left child of root
    root->right = new TreeNode(2);                 // create right child of root
    root->left->left = new TreeNode(3);            // create left child of node 2
    root->left->right = new TreeNode(4);           // create right child of node 2
    root->right->left = new TreeNode(4);           // create left child of right node 2
    root->right->right = new TreeNode(3);          // create right child of right node 2

    Solution obj;                                  // create object of Solution class
    bool result = obj.isSymmetric(root);           // call isSymmetric function

    cout << "Is tree symmetric? ";                 // print message
    if(result) cout << "Yes";                      // print Yes if symmetric
    else cout << "No";                             // print No if not symmetric

    return 0;                                      // end of program
}
