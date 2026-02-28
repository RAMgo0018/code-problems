#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
    void helper(TreeNode* node, int level, vector<int> &arr)   // recursive helper to build left view
    {
        if(node == NULL) return;

        if(arr.size() == level)                                // first node at this level
            arr.push_back(node->val);

        if(node->left)  helper(node->left,  level+1, arr);     // go to left child first
        if(node->right) helper(node->right, level+1, arr);    // then right child
    }

public:
    vector<int> leftSideView(TreeNode* root) {
        vector<int> arr;
        helper(root, 0, arr);
        return arr;
    }
};

int main() {
    /*
            1
           / \
          2   3
           \   \
            5   4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> result = obj.leftSideView(root);

    cout << "Left Side View of Binary Tree: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}
