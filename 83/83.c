/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode ** currPtr = &head;
    while(*currPtr) {
        if ((*currPtr)->next && (*currPtr)->val == (*currPtr)->next->val) {
            *currPtr = (*currPtr)->next;
        } else {
            currPtr = &(*currPtr)->next;
        }
    }
    return head;
}
