/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head) {
        return NULL;
    }
    // check if this node is duplicate
    if (head->next && head->val == head->next->val) {
        // remove duplicate
        while (head->next && head->val == head->next->val) {
            // you may free head here if needed
            head = head->next;
        }
        // now head is still duplicate node (val == last.val)
        // duplicate node will not include in return list
        return deleteDuplicates(head->next);
    } else {
        // not duplicate
        // check next
        head->next = deleteDuplicates(head->next);
        return head;
    }
}

/* struct ListNode* deleteDuplicates(struct ListNode* head){ */
/*     if (!head) { */
/*         return NULL; */
/*     } */
/*     struct ListNode new_head; */
/*     new_head.next = head; */
/*     struct ListNode ** the_next = &new_head.next; */
/*     // struct ListNode * last = head; */
/*     // head = head->next; */
/*     while (head) { */
/*         // printf("%d ", head->val); */
/*         if (head->next && head->next->val == head->val) { */
/*             // repeat element */
/*             struct ListNode * curr = head->next; */
/*             while(curr && curr->val == head->val) { */
/*                 curr = curr->next; */
/*             } */
/*             *the_next = curr; */
/*             head = curr; */
/*             continue; */
/*         } */
/*         the_next = &head->next; */
/*         head = head->next; */
/*     } */
/*     return new_head.next; */
/* } */
