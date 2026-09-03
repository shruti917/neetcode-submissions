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
    void good(TreeNode* root, int maxSoFar, int &count) {
        if (root == NULL)
            return;

        if (root->val >= maxSoFar)
            count++;

        maxSoFar = max(maxSoFar, root->val);

        good(root->left, maxSoFar, count);
        good(root->right, maxSoFar, count);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        good(root,root->val,count);
        return count;
    }
};



