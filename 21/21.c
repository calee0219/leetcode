#include <stdio.h>

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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode * ret;
    struct ListNode ** curr = &ret;
    while (list1 && list2) {
        struct ListNode ** tmp = list1->val < list2->val ? &list1 : &list2;
        //printf("%d ", (*tmp)->val);
        *curr = *tmp;
        *tmp = (*tmp)->next;
        curr = &(*curr)->next;
    }
    *curr = (struct ListNode *)((intptr_t)list1 | (intptr_t)list2);
    return ret;
}
