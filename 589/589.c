/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int dfs(struct Node * node, int ** arr) {
    // printf("%d ", node->val);
    if (*arr) {
        **arr = node->val;
        *arr += 1;
    }
    int count = node->numChildren;
    for (int idx = 0; idx < node->numChildren; ++idx) {
        count += dfs(node->children[idx], arr);
    }
    return count;
}

int* preorder(struct Node* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    // int * ret = NULL;
    // pre-allocate a large size of memory or dfs twice
    int * ret = malloc(10000 * sizeof(int));
    *returnSize = 1 + dfs(root, &ret); // root should be add in count
    // printf("\n%d\n", *returnSize);
    // ret = malloc(sizeof(int) * *returnSize);
    // dfs(root, &ret);
    return ret-*returnSize;
}
