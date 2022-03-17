/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfs(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!(root && subRoot)) {
        // only when both NULL will eq, or pointer will never eq on differnet object
        return root == subRoot;
    }
    return root->val == subRoot->val && dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if (!root) {
        return false;
    }
    return dfs(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
