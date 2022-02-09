#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

// time: O(n), space: O(1)
bool isPalindrome(struct ListNode* head){
    if (head->next == NULL) {
        return true;
    }
    // 1. find second helf
    struct ListNode * first_last = head, * helper_pointer = head;
    while (helper_pointer->next != NULL && helper_pointer->next->next != NULL) {
        first_last = first_last->next;
        helper_pointer = helper_pointer->next->next;
    }
    // second_head in 3 if len=5 (1 base), but we don't need to compare 3 => cmp 1-2 : 4-5
    // second_head in 3 if len=6 (1 base) => cmp 1-3 : 4-5
    struct ListNode * second_head = first_last->next;
    // 2. inplace reverse seconde helf
    struct ListNode * before_pointer = NULL, * after_pointer;
    while (second_head->next != NULL) {
        after_pointer = second_head->next;
        second_head->next = before_pointer;
        before_pointer = second_head;
        second_head = after_pointer;
    }
    second_head->next = before_pointer;
    // 3. compare first & second
    helper_pointer = second_head;
    struct ListNode * first_helper = head;
    while (helper_pointer != NULL) {
        if (helper_pointer->val != first_helper->val) {
            return false;
        }
        helper_pointer = helper_pointer->next;
        first_helper = first_helper->next;
    }
    return true;
    // 4. (option) reverse back second helf
}


// time: O(n), space: O(n)
/* bool isPalindrome(struct ListNode* head){ */
/*     int num[1000000]; */
/*     int digit = 0; */
/*     // Trverse */
/*     struct ListNode * current = head; */
/*     while (current != NULL) { */
/*         num[digit++] = current->val; */
/*         current = current->next; */
/*     } */
/*     int idx; */
/*     int helf = digit / 2 + 1; */
/*     for (idx = 0; idx < helf; ++idx) { */
/*         if (num[idx] != num[digit-1-idx]) { */
/*             return false; */
/*         } */
/*     } */
/*     return true; */
/* } */
