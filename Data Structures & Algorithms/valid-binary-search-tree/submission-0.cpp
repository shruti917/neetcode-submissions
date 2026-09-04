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
    bool bst(TreeNode* root, long long l, long long r) {
        if (root == NULL)
            return true;

        if (root->val <= l || root->val >= r)
            return false;

        bool le = bst(root->left, l, root->val);
        bool ri = bst(root->right, root->val, r);

        return le && ri;
    }

    bool isValidBST(TreeNode* root) {
        return bst(root, LLONG_MIN, LLONG_MAX);
    }
};