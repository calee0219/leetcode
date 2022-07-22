/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // if (!head) return head;
        ListNode ** head_addr = &head;
        ListNode ** ge_ptr = &head;
        ListNode ** lt_ptr = &head;
        for (; *ge_ptr; ge_ptr = &(*ge_ptr)->next) {
            if (*lt_ptr == *ge_ptr) lt_ptr = &(*lt_ptr)->next;
            if ((*ge_ptr)->val >= x) {
                while (*lt_ptr && (*lt_ptr)->val >= x) {
                    lt_ptr = &(*lt_ptr)->next;
                }
                if (*lt_ptr) {
                    // move lt_ptr to ge_ptr
                    ListNode * tmp = *lt_ptr;
                    *lt_ptr = tmp->next;
                    tmp->next = *ge_ptr;
                    *ge_ptr = tmp;
                } else {
                    break;
                }
            }
        }
        return *head_addr;
    }
};