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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root)return false;

        if(samtree(root,subRoot))return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }


    bool samtree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;

        if(root && subRoot && root->val == subRoot->val)
{
        return samtree(root->left,subRoot->left)&& samtree(root->right,subRoot->right);}


        return false;

    }
};
