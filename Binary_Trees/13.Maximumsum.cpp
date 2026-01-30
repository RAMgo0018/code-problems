/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.*/
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
