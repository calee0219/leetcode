class Solution {
    vector<vector<string>> ans;
    void rec(int n, int x, bool col[], bool minus[], bool plus[], vector<int> & tmp) {
        if (x == n) {
            vector<string> v;
            for (auto & t: tmp) {
                string s (n, '.');
                s[t] = 'Q';
                v.push_back(s);
            }
            ans.push_back(v);
            return;
        }
        for (int y = 0; y < n; ++y) {
            if (!col[y] && !plus[x+y] && !minus[9+x-y]) {
                col[y] = plus[x+y] = minus[9+x-y] = true;
                // cout << col[y] << plus[x+y] << minus[9+x-y] << endl;
                tmp.push_back(y);
                rec(n, x+1, col, minus, plus, tmp);
                tmp.pop_back();
                col[y] = plus[x+y] = minus[9+x-y] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        bool col[9], minus[20], plus[20];
        memset(col, 0, sizeof(col));
        memset(minus, 0, sizeof(minus));
        memset(plus, 0, sizeof(plus));
        vector<int> tmp;
        rec(n, 0, col, minus, plus, tmp);
        return ans;
    }
};