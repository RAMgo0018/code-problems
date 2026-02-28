/*Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]*/
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};

int main() {
    /*
        Example Tree:
              1
             / \
            2   3
           / \
          4   5

        Postorder Traversal (Iterative, 2 stacks): 4 5 2 3 1
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder Traversal (Iterative - 2 Stacks): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

