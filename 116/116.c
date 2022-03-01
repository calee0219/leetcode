/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (!root) {
        return root;
    }
    struct Node * left_most = root;
    // we'll connect each level via iterate it's parent level
    // in this situation, we promise parent already connect together
    while (left_most->left) { // check if next level exist
        struct Node * curr = left_most;
        while (curr) {
            // printf("%d ", curr->val);
            curr->left->next = curr->right;
            if (curr->next) {
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
        }
        left_most = left_most->left;
    }
    return root;
}

// struct Node* connect(struct Node* root) {
// 	if (!root) {
//         return root;
//     }
//     if (root->left) { // perfect tree so with left, there will be right
//         root->left->next = root->right;
//     }
//     if (root->next && root->right) { // with next, your right child should have next
//         root->right->next = root->next->left;
//     }
//     connect(root->left);
//     connect(root->right);
//     return root;
// }
