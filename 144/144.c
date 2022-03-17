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

// Morris traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize){
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
                tmp->right = NULL;
                node = node->right;
            } else {
                // true leaf
                arr[arr_idx++] = node->val;
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
