/*Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        if (abs(lh - rh) > 1) return false;

        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;

        return true;
    }
};

int main() {
    /*
        Example Tree (Balanced):
              1
             / \
            2   3
           /
          4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;

    if (sol.isBalanced(root))
        cout << "The binary tree is balanced." << endl;
    else
        cout << "The binary tree is NOT balanced." << endl;

    return 0;
}
