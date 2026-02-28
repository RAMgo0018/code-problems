/*Given a root of a Binary Tree, return its boundary traversal in the following order:

Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.

Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, */
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool leafnode(Node* node) {
        return node && node->left == NULL && node->right == NULL;
    }

    void addleftnode(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!leafnode(curr))
                res.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addrightnode(Node* root, vector<int>& res) {
        Node* curr = root->right;
        stack<int> st;

        while (curr) {
            if (!leafnode(curr))
                st.push(curr->data);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
    }

    void addleafnodes(Node* root, vector<int>& res) {
        if (!root) return;

        if (leafnode(root)) {
            res.push_back(root->data);
            return;
        }

        addleafnodes(root->left, res);
        addleafnodes(root->right, res);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;

        if (!leafnode(root))
            res.push_back(root->data);

        addleftnode(root, res);
        addleafnodes(root, res);
        addrightnode(root, res);

        return res;
    }
};

int main() {
    /*
        Example Tree:
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
              / \
             8   9

        Boundary Traversal:
        1 2 4 8 9 6 7 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
