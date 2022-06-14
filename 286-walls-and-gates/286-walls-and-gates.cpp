class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        pair<int,int> dirs[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        queue<pair<int,pair<int,int>>> q;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (rooms[x][y] == 0)
                    q.push({0, {x, y}});
            }
        }
        while (!q.empty()) {
            int level = q.front().first;
            auto coordinate = q.front().second;
            // cout << coordinate.first << ":" << coordinate.second << " " << level << endl;
            q.pop();
            for (auto & dir: dirs) {
                auto nc = coordinate;
                nc.first += dir.first; nc.second += dir.second;
                if (nc.first >= 0 && nc.first < m && nc.second >= 0 && nc.second < n && level+1 < rooms[nc.first][nc.second]) {
                    rooms[nc.first][nc.second] = level+1;
                    q.push({level+1, nc});
                }
            }
        }
    }
};