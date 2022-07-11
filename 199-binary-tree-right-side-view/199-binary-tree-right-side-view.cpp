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
    void dfs(TreeNode * node, int depth, vector<int>& ans) {
        if (!node) { return; }
        if (ans.size() == depth) {
            ans.push_back(node->val);
        }
        dfs(node->right, depth+1, ans);
        dfs(node->left, depth+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        dfs(root, 0, ans);
        return ans;
    }
};