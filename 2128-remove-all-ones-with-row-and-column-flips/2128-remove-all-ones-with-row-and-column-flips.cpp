class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        for (int x = 0; x < grid.size(); ++x) {
            if (grid[x][0]) {
                for (int y = 0; y < grid[0].size(); ++y) {
                    grid[x][y] = !grid[x][y];
                }
            }
        }
        for (int y = 0; y < grid[0].size(); ++y) {
            for (int x = 1; x < grid.size(); ++x) {
                if (grid[x][y] != grid[0][y])
                    return false;
            }
        }
        return true;
    }
};