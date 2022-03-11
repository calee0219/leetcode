/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head) {
        return NULL;
    }
    struct ListNode ** curr = &head;
    int len = 0;
    while(*curr) {
        len++;
        curr = &(*curr)->next;
    }
    (*curr) = head;
    len -= k%len + 1;
    // printf("%d\n", len);
    while (len--) {
        // printf("%d ", head->val);
        head = head->next;
    }
    curr = &(head->next);
    head = head->next;
    (*curr) = NULL;
    return head;
}
