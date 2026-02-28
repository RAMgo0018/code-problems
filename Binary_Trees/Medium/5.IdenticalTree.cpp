/*Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
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
    int maxi = INT_MIN;

    int maximum(TreeNode* root) {
        if (root == NULL) return 0;

        int left = max(0, maximum(root->left));
        int right = max(0, maximum(root->right));

        // update maximum path sum
        maxi = max(maxi, root->val + left + right);

        // return max path going down
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maximum(root);
        return maxi;
    }
};

int main() {
    /*
        Example Tree:
               -10
               /  \
              9   20
                 /  \
                15   7

        Maximum Path Sum = 42
        (15 -> 20 -> 7)
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.maxPathSum(root);

    cout << "Maximum Path Sum of Binary Tree: " << result << endl;

    return 0;
}
