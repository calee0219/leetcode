class Solution {
    int ans;
    void rec(int n, int x, bool col[], bool minus[], bool plus[]) {
        if (x == n) {
            ans += 1;
            return;
        }
        for (int y = 0; y < n; ++y) {
            if (!col[y] && !plus[x+y] && !minus[9+x-y]) {
                col[y] = plus[x+y] = minus[9+x-y] = true;
                rec(n, x+1, col, minus, plus);
                col[y] = plus[x+y] = minus[9+x-y] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        bool col[9], minus[20], plus[20];
        memset(col, 0, sizeof(col));
        memset(minus, 0, sizeof(minus));
        memset(plus, 0, sizeof(plus));
        rec(n, 0, col, minus, plus);
        return ans;
    }
};