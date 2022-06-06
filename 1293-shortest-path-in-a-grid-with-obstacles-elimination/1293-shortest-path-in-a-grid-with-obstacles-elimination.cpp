class Solution {
    pair<int,int> dirs[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited (m, vector<int> (n, -1));
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{k, 0}, {0,0}});
        while(!q.empty()) {
            int remain = q.front().first.first;
            int step = q.front().first.second;
            int x = q.front().second.first;
            int y = q.front().second.second;
            if (x == m-1 && y == n-1) {
                // cout << remain << endl;
                return step;
            }
            q.pop();
            for (auto & d: dirs) {
                int nX = x + d.first;
                int nY = y + d.second;
                if (nX < m && nX >= 0 && nY < n && nY >= 0 && visited[nX][nY] < remain) {
                    if (remain >= grid[nX][nY]) {
                        // block
                        int tmp = remain-grid[nX][nY];
                        q.push({{tmp, step+1}, {nX, nY}});
                        visited[nX][nY] = tmp;
                    }
                }
            }
        }
        return -1;
    }
};