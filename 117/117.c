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
	struct Node * left_most = root;
    while (left_most) {
        printf("%p ", left_most);
        struct Node * curr = left_most;
        struct Node * before = NULL;
        left_most = NULL;
        while (curr) {
            if (curr->left) {
                if (!before) {
                    // before not exist, it's first node
                    left_most = curr->left;
                    before = curr->left;
                } else {
                    before->next = curr->left;
                    before = curr->left;
                }
            }
            if (curr->right) {
                if (!before) {
                    // before not exist, it's first node
                    left_most = curr->right;
                    before = curr->right;
                } else {
                    before->next = curr->right;
                    before = curr->right;
                }
            }
            curr = curr->next;
        }
        if (before) {
            before->next = NULL;
        }
    }
    return root;
}
