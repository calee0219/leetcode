/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSymmetric(struct TreeNode* root){
    struct TreeNode * l = root->left;
    struct TreeNode * r = root->right;
    while (l || r) {
        // if (l) printf("%d  ", l->val); else printf("#  ");
        // if (r) printf("%d\n", r->val); else printf("#\n");
        if (!l || !r || l->val != r->val) {
            return false;
        }
        if (r->right) {
            struct TreeNode * rTmp = r->right;
            while (rTmp->left && rTmp->left != r) {
                rTmp = rTmp->left;
            }
            if (!rTmp->left) {
                rTmp->left = r;
                r = r->right;
            } else {
                rTmp->left = NULL;
                r = r->left;
            }
        } else {
            r = r->left;
        }
        if (l->left) {
            struct TreeNode * lTmp = l->left;
            while (lTmp->right && lTmp->right != l) {
                lTmp = lTmp->right;
            }
            if (!lTmp->right) {
                lTmp->right = l;
                l = l->left;
            } else {
                lTmp->right = NULL;
                l = l->right;
            }
        } else {
            l = l->right;
        }
    }
    return true;
}
