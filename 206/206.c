#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* reverseList(struct ListNode* head){
    if (!head) {
        return head;
    }
    struct ListNode * before = head;
    head = head->next;
    before->next = NULL;
    while(head) {
        struct ListNode * after = head->next;
        head->next = before;
        before = head;
        head = after;
    }
    return before;
}
