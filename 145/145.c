/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int tmp[101];
    int tmp_idx = 0;
    struct TreeNode * stack[101];
    int stack_idx = 0;
    while (root || stack_idx > 0) {
        if (root) {
            tmp[tmp_idx++] = root->val;
            if (root->left) {
                stack[stack_idx++] = root->left;
            }
            root = root->right;
        } else {
            root = stack[--stack_idx];
        }
    }
    *returnSize = tmp_idx;
    int * ret = malloc(tmp_idx * sizeof(int));
    while (tmp_idx--) {
        ret[*returnSize - tmp_idx - 1] = tmp[tmp_idx];
    }
    return ret;
}
