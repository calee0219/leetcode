/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(int ** arr, struct TreeNode * node) {
    if (!node) {
        return 0;
    }
    **arr = node->val;
    (*arr)++;
    return 1 + dfs(arr, node->left) + dfs(arr, node->right);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int * arr = malloc(101 * sizeof(int));
    *returnSize = dfs(&arr, root);
    int * ans = malloc(*returnSize * sizeof(int));
    memcpy(ans, arr-*returnSize, *returnSize * sizeof(int));
    free(arr-*returnSize);
    return ans;
}
