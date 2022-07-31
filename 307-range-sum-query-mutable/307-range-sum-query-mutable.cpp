struct Node {
    Node * left, * right;
    int l_idx, r_idx; // includesive
    int sum;
    Node (int l, int r, int s, Node * ln, Node * rn): left(ln), right(rn), l_idx(l), r_idx(r), sum(s) {}
    Node (int l, int r, int s): Node(l, r, s, NULL, NULL) { }
    Node (int l, int r): Node(l, r, 0) { }
};

class NumArray {
    Node * root;
    Node * build_tree(vector<int>& nums, int l, int r) {
        if (l == r) {
            return new Node(l, r, nums[l]);
        } else {
            int med = l + (r-l) / 2;
            Node * l_node = build_tree(nums, l, med);
            Node * r_node = build_tree(nums, med+1, r);
            return new Node(l, r, l_node->sum + r_node->sum, l_node, r_node);
        }
    }
    void update_tree(Node * node, int index, int val) {
        if (node->l_idx == node->r_idx) {
            if (index != node->l_idx) {
                cout << "!!!!! wow error !!!!! " << index << " " << node->l_idx << endl;
            }
            node->sum = val;
        } else {
            int med = node->l_idx + (node->r_idx - node->l_idx) / 2;
            if (index > med) {
                update_tree(node->right, index, val);
            } else {
                update_tree(node->left, index, val);
            }
            node->sum = node->left->sum + node->right->sum;
        }
    }
    int sum_tree(Node * node, int l, int r) {
        if (node->l_idx == l && node->r_idx == r) {
            return node->sum;
        }
        int med = node->l_idx + (node->r_idx - node->l_idx) / 2;
        if (l <= med && r > med) {
            return sum_tree(node->left, l, med) + sum_tree(node->right, med+1, r);
        }
        if (l > med) {
            return sum_tree(node->right, l, r);
        }
        if (r <= med) {
            return sum_tree(node->left, l, r);
        }
        cout << "????? " << l << " " << med << " " << r << endl;
        return 0;
    }
public:
    NumArray(vector<int>& nums) {
        // build segment tree
        root = build_tree(nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        update_tree(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum_tree(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */