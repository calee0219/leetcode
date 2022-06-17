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
    unordered_map<TreeNode*,int> memory[3];
    int helper1(TreeNode * node) {
        // 點一定要填色
        if (!node) return 0;
        if (memory[0].find(node) != memory[0].end()) return memory[0][node];
        memory[0][node] = 1 + helper3(node->left) + helper3(node->right);
        return memory[0][node];
    }
    int helper2(TreeNode * node) {
        // 點一定要被下面覆蓋到
        if (!node) return 0;
        if (memory[1].find(node) != memory[1].end()) return memory[1][node];
        int ret = 1 + helper3(node->left) + helper3(node->right);
        // int a = ret;
        if (node->left)
            ret = min(ret, helper1(node->left) + helper2(node->right));
        // int b = ret;
        if (node->right)
            ret = min(ret, helper2(node->left) + helper1(node->right));
        // cout << "=====\n" << a << " " << b << " " << ret << endl;
        memory[1][node] = ret;
        return memory[1][node];;
    }
    int helper3(TreeNode * node) {
        // 點已被覆蓋，可任意操作
        if (!node) return 0;
        if (memory[2].find(node) != memory[2].end()) return memory[2][node];
        memory[2][node] = min(1 + helper3(node->left) + helper3(node->right),
                              helper2(node->left) + helper2(node->right));
        return memory[2][node];
    }
public:
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return helper2(root);
    }
};