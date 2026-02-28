/*Example 1:

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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> st;
        vector<int> ans;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top()->right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
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

        Postorder Traversal (Iterative - 1 Stack): 4 5 2 3 1
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder Traversal (Iterative - 1 Stack): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
