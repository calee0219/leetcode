/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if (!root) {
        return NULL;
    }
    // swap left , right
    root->left = (uintptr_t)root->right ^ (uintptr_t)root->left;
    root->right = (uintptr_t)root->right ^ (uintptr_t)root->left;
    root->left = (uintptr_t)root->right ^ (uintptr_t)root->left;
    invertTree(root->right);
    invertTree(root->left);
    return root;
}