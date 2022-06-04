struct SegNode {
    int l_idx, r_idx;
    int max_val;
    long long int total_val;
    SegNode * left;
    SegNode * right;
    SegNode(int l, int r, int v, long long int total): l_idx(l), r_idx(r), max_val(v), total_val(total), left(NULL), right(NULL) {}
};

class BookMyShow {
    SegNode * buildTree(int start, int end, int val) {
        // cout << start << " " << end << endl;
        if (start == end) return new SegNode(start, end, val, val);
        int mid = (start + end) / 2;
        SegNode * node = new SegNode(start, end, val, (long long int)(end - start + 1) * val);
        node->left = buildTree(start, mid, val);
        node->right = buildTree(mid+1, end, val);
        return node;
    }
    vector<int> gatherHelper(SegNode * node, int k, int maxRow) {
        if (node->left == NULL) {
            if (node->r_idx <= maxRow) {
                int col = col_num - node->max_val;
                node->max_val -= k;
                node->total_val -= k;
                return {node->r_idx, col};
            } else {
                return {};
            }
        }
        vector<int> ret;
        if (node->left->max_val >= k) {
            ret = gatherHelper(node->left, k, maxRow);
        } else {
            ret = gatherHelper(node->right, k, maxRow);
        }
        node->max_val = max(node->left->max_val, node->right->max_val);
        node->total_val = node->left->total_val + node->right->total_val;
        return ret;
    }
    long long int sum_before(SegNode * node, int R) {
        // if (!node) return 0;
        if (node->r_idx == R) return node->total_val;
        if (R > node->left->r_idx) {
            return node->left->total_val + sum_before(node->right, R);
        } else {
            return sum_before(node->left, R);
        }
    }
    void scatterHelper(SegNode * node, int & k) {
        if (k == 0) return;
        if (node->left == NULL) {
            if (node->max_val < k) {
                k -= node->max_val;
                node->max_val = 0;
                node->total_val = 0;
                return;
            } else {
                node->max_val -= k;
                node->total_val -= k;
                k = 0;
                return;
            }
        } else {
            scatterHelper(node->left, k);
            scatterHelper(node->right, k);
            node->max_val = max(node->left->max_val, node->right->max_val);
            node->total_val = node->left->total_val + node->right->total_val;
            return;
        }
    }
    SegNode * root;
    int col_num;
public:
    BookMyShow(int n, int m) {
        col_num = m;
        root = buildTree(0, n-1, m);
        // cout << root->total_val << endl;
    }
    
    vector<int> gather(int k, int maxRow) {
        // cout << "G" << endl;
        if (root->max_val < k) return {};
        return gatherHelper(root, k, maxRow);
    }
    
    bool scatter(int k, int maxRow) {
        // cout << "S" << endl;
        if (root->total_val < k) return false;
        if (sum_before(root, maxRow) < k) return false;
        scatterHelper(root, k);
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */