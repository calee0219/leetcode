/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node * tmp = q.front();
            q.pop();
            if (tmp->left) {
                q.push(tmp->left);
                q.push(tmp->right);
            }
            tmp->next = q.front();
        }
        Node * curr = root;
        while (curr) {
            curr->next = NULL;
            curr = curr->right;
        }
        return root;
    }
};
