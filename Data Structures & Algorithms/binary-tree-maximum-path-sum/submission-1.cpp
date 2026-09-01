/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int res = INT_MIN;

    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        // Ignore negative paths
        left = max(0, left);
        right = max(0, right);

        // Path passing through current node
        res = max(res, root->val + left + right);

        // Return path that can be extended to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }
};