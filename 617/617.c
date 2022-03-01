#include <stdlib.h>
#include <string.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

struct TreeNode * dfs(struct TreeNode * n1, struct TreeNode * n2) {
    if (!n1) {
        return n2;
    }
    if (!n2) {
        return n1;
    }
    n1->val = n1->val + n2->val;
    n1->left = dfs(n1->left, n2->left);
    n1->right = dfs(n1->right, n2->right);
    return n1;
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    struct TreeNode * ret = NULL;
    ret = dfs(root1, root2);
    return ret;
}
