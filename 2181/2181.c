#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeNodes(struct ListNode* head){
    // Link List triverse
    struct ListNode * current = head;
    struct ListNode * new = NULL;
    struct ListNode * newCurr = new;
    int sum = 0;
    while(current) {
        if (current->val) {
            sum += current->val;
        } else {
            if (sum == 0) {
                continue;
            }
            struct ListNode * tmpNode = malloc(sizeof(struct ListNode));
            tmpNode->val = sum;
            tmpNode->next = NULL;
            if (new == NULL) {
                newCurr = tmpNode;
                new = tmpNode;
            } else {
                newCurr->next = tmpNode;
                newCurr = newCurr->next;
            }
            sum = 0;
        }
        current = current->next;
    }
    return new;
}

int main() {
    return 0;
}
