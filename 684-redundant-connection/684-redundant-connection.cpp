class Solution {
    unordered_map<int,int> visited;
    void uni(int a, int b) {
        visited[find(a)] = find(b);
    }
    int find(int a) {
        if (visited.find(a) == visited.end()) {
            visited.insert({a, a});
            return a;
        }
        if (visited[a] == a) return a;
        visited[a] = find(visited[a]);
        return visited[a];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto & e: edges) {
            if (find(e[0]) == find(e[1]))
                return e;
            uni(e[0], e[1]);
        }
        return {};
    }
};