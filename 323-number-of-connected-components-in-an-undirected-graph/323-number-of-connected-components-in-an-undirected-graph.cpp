class Solution {
    vector<int> group;
    int find(int curr) {
        if (group[curr] == curr)
            return curr;
        group[curr] = find(group[curr]);
        return group[curr];
    }
    void uni(int A, int B) {
        int a = find(A);
        int b = find(B);
        group[a] = b;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        group.resize(n);
        for (int idx = 0; idx < n; ++idx)
            group[idx] = idx;
        for (auto & e: edges) {
            uni(e[0], e[1]);
        }
        int ans = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (idx == group[idx])
                ans += 1;
        }
        return ans;
    }
};