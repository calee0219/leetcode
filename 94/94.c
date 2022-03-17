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
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int * ret = malloc(101 * sizeof(int));
    int idx = 0;
    struct TreeNode * node = root;
    struct TreeNode * stack[101];
    int stack_idx = 0;
    while(node || stack_idx > 0) {
        if (node) {
            stack[stack_idx++] = node;
            node = node->left;
        } else {
            if (stack[--stack_idx]->right) {
                node = stack[stack_idx]->right;
            }
            ret[idx++] = stack[stack_idx]->val;
        }
    }
    *returnSize = idx;
    return ret;
}

// Morris Traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int * arr = malloc(101 * sizeof(int));
    size_t arr_idx = 0;
    struct TreeNode * node = root;
    while (node) {
        if (node->left) {
            struct TreeNode * tmp = node->left;
            // need to check cycle here
            while (tmp->right && tmp->right != node) {
                tmp = tmp->right;
            }
            if (tmp->right) {
                // here's the cycle, tmp->right = node
                arr[arr_idx++] = node->val;
                node = node->right;
            } else {
                // true leaf
                tmp->right = node;
                node = node->left;
            }
        } else {
            arr[arr_idx++] = node->val;
            node = node->right;
        }
    }
    // printf("%d ", arr_idx);
    *returnSize = arr_idx;
    return arr;
}
