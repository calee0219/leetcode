class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph (n, vector<int>());
        for (auto & e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited (n, false);
        queue<pair<int,int>> q;
        q.push({0,-1});
        while (!q.empty()) {
            int curr = q.front().first;
            int prt = q.front().second;
            q.pop();
            visited[curr] = true;
            for (auto & next: graph[curr]) {
                if (next == prt) continue;
                if (visited[next]) return false;
                q.push({next, curr});
            }
        }
        for (auto v: visited) {
            if (v == false) return false;
        }
        return true;
    }
};