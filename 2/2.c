/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * ans;
    struct ListNode ** currPtr = &ans;
    int carry = 0;
    while (l1 || l2 || carry) {
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        *currPtr = malloc(sizeof(struct ListNode));
        (*currPtr)->val = carry % 10;
        currPtr = &((*currPtr)->next);
        carry /= 10;
    }
    *currPtr = NULL; // make the tail `->next` `NULL`
    return ans;
}
