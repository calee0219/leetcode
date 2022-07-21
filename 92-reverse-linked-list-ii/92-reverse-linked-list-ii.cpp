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
    void rec(ListNode * node, int right, ListNode ** replace, int until) {
        if (right > 0)
            rec(node->next, right-1, replace, until);
        cout << right << " " << until << endl;
        if (right < until) {
            swap((*replace)->val, node->val);
            *replace = (*replace)->next;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--;
        right--;
        ListNode * node = head;
        for (int idx = 0; idx < left; ++idx)
            node = node->next;
        // cout << node->val;
        rec(head, right, &node, (right-left+1)/2);
        return head;
    }
};