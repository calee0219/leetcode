/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	struct Node * clone_head = NULL;
    struct Node ** clone_currPtr = &clone_head;
    struct Node * indexing[1001] = {};
    struct Node * curr = head;
    while (curr) {
        // printf("%p|%d ", curr, (curr-head)/2);
        *clone_currPtr = malloc(sizeof(struct Node));
        (*clone_currPtr)->val = curr->val;
        (*clone_currPtr)->next = NULL;
        (*clone_currPtr)->random = NULL;
        // Warning: if the linked list not continously, this hash function may be danger
        indexing[(curr-head)>>1] = (*clone_currPtr);
        clone_currPtr = &(*clone_currPtr)->next;
        curr = curr->next;
    }
    // printf("\n=====\n");
    clone_currPtr = &clone_head;
    curr = head;
    while (curr) {
        // printf("%p|%d ", curr->random, (curr->random-head)>>1);
        if (curr->random != NULL) {
            (*clone_currPtr)->random = indexing[(curr->random-head)>>1];
        }
        clone_currPtr = &(*clone_currPtr)->next;
        curr = curr->next;
    }
    return clone_head;
}
