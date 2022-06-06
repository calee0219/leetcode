/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *nA = headA, *nB = headB;
    while(nA != nB) {
        nA = nA == NULL ? headB : nA->next;
        nB = nB == NULL ? headA : nB->next;
    }
    return nA;
}