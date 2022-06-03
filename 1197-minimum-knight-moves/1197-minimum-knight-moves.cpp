class Solution {
public:
    int minKnightMoves(int x, int y) {
        int tx = abs(x) + 2;
        int ty = abs(y) + 2;
        // cout << tx << " " << ty << endl;
        int step[310][310] = {};
        pair<int,int> dir[] = {{2,1}, {1,2}, {2,-1}, {1,-2}, {-2,-1}, {-1,-2}, {-2,1}, {-1,2}};
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{2,2}});
        while (!q.empty()) {
            int cx = q.front().second.first;
            int cy = q.front().second.second;
            int lev = -q.front().first;
            q.pop();
            for (auto & d: dir) {
                int nx = cx + d.first;
                int ny = cy + d.second;
                // cout << nx << " " << ny << endl;
                if (nx == 2 && ny == 2) continue;
                if (nx >= 0 && ny >= 0 && nx < 310 && ny < 310 && step[nx][ny] == 0) {
                    if (nx == tx && ny == ty) return lev+1;
                    step[nx][ny] = lev + 1;
                    q.push({-lev-1, {nx, ny}});
                }
            }
        }
        return step[tx][ty];
    }
};