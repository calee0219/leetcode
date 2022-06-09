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
    int helper(TreeNode * node, int curr) {
        if (!node) return 0;
        return (node->val >= curr) + helper(node->left, max(curr, node->val)) + helper(node->right, max(curr, node->val));
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};