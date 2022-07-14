/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // void print(TreeNode* node) {
    //     queue<pair<char,TreeNode*>> q;
    //     q.push(make_pair('r', node));
    //     while(!q.empty()) {
    //         queue<pair<char,TreeNode*>> p = q;
    //         while(!p.empty()) {
    //             pair<char,TreeNode *> tmp = p.front();
    //             p.pop();
    //             q.pop();
    //             printf("%c:%d ", tmp.first, tmp.second->val);
    //             if (tmp.second->left) q.push(make_pair('l', tmp.second->left));
    //             if (tmp.second->right) q.push(make_pair('r', tmp.second->right));
    //         }
    //         printf("\n");
    //     }
    // }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_t in_idx = 0;
        TreeNode * head = NULL, *parent = NULL;
        TreeNode ** nextPtr = &head;
        for (size_t pre_idx = 0; pre_idx < preorder.size(); ++pre_idx) {
            *nextPtr = new TreeNode ( preorder[pre_idx], NULL, parent );
            // printf("%d %p %p %p %p | %d %d\n", (*nextPtr)->val, *nextPtr, (*nextPtr)->left, (*nextPtr)->right, parent, inorder[in_idx], preorder[pre_idx]);
            if (inorder[in_idx] == preorder[pre_idx]) {
                // go right
                nextPtr = &(*nextPtr)->right;
                in_idx += 1;
                // printf("%d/%d ", (*nextPtr)->val, inorder[in_idx]);
                while (*nextPtr && in_idx < inorder.size()
                         && (*nextPtr)->val == inorder[in_idx]) {
                    // printf("%d/%d %p ", (*nextPtr)->val, inorder[in_idx], *nextPtr);
                    TreeNode ** tmp = nextPtr;
                    nextPtr = &(*nextPtr)->right;
                    *tmp = NULL;
                    parent = *nextPtr;
                    in_idx += 1;
                }
                // printf("%p %p\n", *nextPtr, parent);
                // printf("| %d %d\n", preorder[pre_idx], inorder[in_idx]);
            } else {
                // go left
                parent = (*nextPtr);
                nextPtr = &(*nextPtr)->left;
            }
        }
        // print(head);
        // printf("YOYH");
        return head;
    }
};