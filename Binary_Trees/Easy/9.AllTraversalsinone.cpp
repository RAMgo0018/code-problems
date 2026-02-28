/*Given a binary tree with root node. Return the In-order,Pre-order and Post-order traversal of the binary tree.


Example 1

Input : root = [1, 3, 4, 5, 2, 7, 6 ]

Output : [ [5, 3, 2, 1, 7, 4, 6] , [1, 3, 5, 2, 4, 7, 6] , [5, 2, 3, 7, 6, 4, 1] ]

Explanation : The In-order traversal is [5, 3, 2, 1, 7, 4, 6].

The Pre-order traversal is [1, 3, 5, 2, 4, 7, 6].

The Post-order traversal is [5, 2, 3, 7, 6, 4, 1].*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> preorder, inorder, postorder;

        if (root == NULL) return ans;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) {
                preorder.push_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->left)
                    st.push({it.first->left, 1});
            }
            else if (it.second == 2) {
                inorder.push_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->right)
                    st.push({it.first->right, 1});
            }
            else {
                postorder.push_back(it.first->data);
            }
        }

        ans.push_back(inorder);
        ans.push_back(preorder);
        ans.push_back(postorder);

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
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> result = sol.treeTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : result[0]) cout << x << " ";
    cout << endl;

    cout << "Preorder Traversal: ";
    for (int x : result[1]) cout << x << " ";
    cout << endl;

    cout << "Postorder Traversal: ";
    for (int x : result[2]) cout << x << " ";
    cout << endl;

    return 0;
}
