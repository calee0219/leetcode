class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph (n, vector<int>());
        for (auto & e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited (n, false);
        queue<int> q;
        int ans = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (visited[idx] == false) {
                ans += 1;
                q.push(idx);
                while(!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    visited[curr] = true;
                    for (auto & next: graph[curr]) {
                        if (visited[next] == false)
                            q.push(next);
                    }
                }
            }
        }
        return ans;
    }
};