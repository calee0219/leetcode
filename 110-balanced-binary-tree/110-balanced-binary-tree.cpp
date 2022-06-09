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
    int helper(TreeNode * node, bool & ans) {
        if (!node) return 0;
        int l = helper(node->left, ans);
        int r = helper(node->right, ans);
        if (abs(l-r) > 1)
            ans = false;
        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        helper(root, ans);
        return ans;
    }
};