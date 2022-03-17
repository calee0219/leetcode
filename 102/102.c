/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define QSIZE 2020

struct pair {
    size_t level;
    struct TreeNode * node;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    struct pair queue[QSIZE];
    size_t q_start = 0, q_end = 0;
    // each level arr
    int arr[QSIZE];
    size_t arr_idx = 0;
    // ret val
    int ** ret = malloc(QSIZE * sizeof(int*));
    *returnColumnSizes = malloc(QSIZE * sizeof(int));
    // push root
    queue[q_end].level = 0;
    queue[q_end].node = root;
    q_end = (q_end + 1) % QSIZE;
    *returnSize = 0;
    while(q_start != q_end) {
        // pop from queue
        struct TreeNode * t_node = queue[q_start].node;
        int t_level = queue[q_start].level;
        q_start = (q_start + 1) % QSIZE;
        // printf("%d %d | %d %d\n", t_level, t_node->val, arr_idx, *returnSize);
        if (*returnSize != t_level) {
            int * tmp = malloc(arr_idx * sizeof(int));
            memcpy(tmp, arr, arr_idx*sizeof(int));
            (*returnColumnSizes)[*returnSize] = arr_idx;
            ret[*returnSize] = tmp;
            *returnSize = t_level;
            arr_idx = 0;
            arr[arr_idx++] = t_node->val;
        } else {
            arr[arr_idx++] = t_node->val;
        }
        // push to queue
        if (t_node->left) {
            queue[q_end].level = t_level+1;
            queue[q_end].node = t_node->left;
            q_end = (q_end + 1) % QSIZE;
        }
        if (t_node->right) {
            queue[q_end].level = t_level+1;
            queue[q_end].node = t_node->right;
            q_end = (q_end + 1) % QSIZE;
        }
    }
    int * tmp = malloc(arr_idx * sizeof(int));
    memcpy(tmp, arr, arr_idx*sizeof(int));
    (*returnColumnSizes)[*returnSize] = arr_idx;
    ret[*returnSize] = tmp;
    (*returnSize)++;
    return ret;
}
