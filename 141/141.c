/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // if (!head) {
    //     return false;
    // }
    // struct ListNode * fast = head;
    // struct ListNode * slow = head;
    // while (fast->next && fast->next->next && slow->next) {
    //     fast = fast->next->next;
    //     slow = slow->next;
    //     if (fast == slow) {
    //         return true;
    //     }
    // }
    // return false;
    struct ListNode * end = malloc(sizeof(struct ListNode)); // use end to end the loop list
    end->next = NULL;
    while (head && head->next) {
        struct ListNode * tmp = head->next;
        head->next = end;
        head = tmp;
    }
    if (head == end) {
        return true;
    } else {
        return false;
    }
}
