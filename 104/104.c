/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if (!root)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    // return 1 + (l > r ? l : r);
    return 1 + l - (((l-r)>>31)&1) * (l-r);
}
