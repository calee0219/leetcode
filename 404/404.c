/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumOfLeftLeaves(struct TreeNode* root){
    int ans = 0;
    struct TreeNode * node = root;
    while (node) {
        if (node->left) {
            struct TreeNode * tmp = node->left;
            if (!tmp->left && !tmp->right) {
                ans += tmp->val;
            }
            while (tmp->right && tmp->right != node) {
                tmp = tmp->right;
            }
            if (!tmp->right) {
                tmp->right = node;
                node = node->left;
            } else {
                // if (!tmp->left && tmp->right->left == tmp) {
                //     printf("%d ", tmp->val);
                //     ans += tmp->val;
                // }
                tmp->right = NULL;
                node = node->right;
            }
        } else {
            node = node->right;
        }
    }
    return ans;
}
