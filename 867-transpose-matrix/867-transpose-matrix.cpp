class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> new_matrix (n, vector<int>(m, 0));
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                new_matrix[y][x] = matrix[x][y];
            }
        }
        return new_matrix;
    }
};