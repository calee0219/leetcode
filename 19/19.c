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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode * first = head;
    struct ListNode * second = head;
    while (n--) {
        first = first->next;
    }
    if (!first) {
        return head->next;
    }
    first = first->next;
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return head;
}

/* struct ListNode* removeNthFromEnd(struct ListNode* head, int n){ */
/*     struct ListNode * first = head; */
/*     struct ListNode * second = head; */
/*     struct ListNode * before = NULL; */
/*     size_t idx; */
/*     for (idx = 0; idx < n && first; ++idx) { */
/*         first = first->next; */
/*     } */
/*     while (first) { */
/*         first = first->next; */
/*         before = second; */
/*         second = second->next; */
/*     } */
/*     if (before) { */
/*         before->next = second->next; */
/*         return head; */
/*     } else { */
/*         return second->next; */
/*     } */
/* } */
